# Valgrind & AI Memory Tracer — Memory Error Analysis

**Project:** `ai_memory_visualizer_valgrind_tracer`  
**Programs analyzed:** `programs/heap_example.c` and `programs/aliasing_example.c`  
**Purpose:** Connect memory-tool diagnostics to specific allocations, deallocations, pointer aliases, and object lifetimes.  
**Status:** **Source analysis completed; student Valgrind logs still required.** Expected Memcheck warnings are identified below, but they must not be represented as measured Valgrind output until the commands in §1 have been run and compared against the actual log.

## 1. Tools, method, and evidence

I reviewed the provided program sources and the memory-lifetime model from Task 0 (`analysis/memory_maps.md`). The code was also reproduced in a separate GCC/AddressSanitizer environment to corroborate the primary defects. **Valgrind was not available in that environment; no Valgrind log has been collected for this report yet.** AddressSanitizer/LeakSanitizer findings are independent evidence, **not** Valgrind findings.

Run the following commands on the original Holberton programs from inside `programs/`:

```bash
make
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all \
  --track-origins=yes --num-callers=20 ./heap_example 2>&1 | tee /tmp/heap_valgrind.log
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all \
  --track-origins=yes --num-callers=20 ./aliasing_example 2>&1 | tee /tmp/aliasing_valgrind.log
```

If a recent GCC rejects the intentionally unsafe code because `-Werror` turns `-Wuse-after-free` into a fatal error, recompile **without changing the source** using:

```bash
make CFLAGS='-Wall -Wextra -Werror -pedantic -std=gnu89 -g -Wno-error=use-after-free'
```

The `-g` flag allows the diagnostic to identify source locations. `--leak-check=full` produces detailed leak records; `--show-leak-kinds=all` includes all reachability categories; `--track-origins=yes` assists if an uninitialized-value warning occurs. Runtime addresses, process IDs, diagnostic grouping, and library stack traces will vary.

## 2. `heap_example.c` — lost ownership and a memory leak

### 2.1 Allocation and ownership timeline

The successful path creates two `Person` objects. Each `Person` is itself a heap allocation and contains a `name` pointer to **another, independently allocated heap block**.

| Step | Operation and source line | Memory state |
|---|---|---|
| H1 | `person_new("Alice", 30)` from `main` (line 51) | Allocates a `Person` struct (line 14) and a separate 6-byte `name` block (line 21), containing `A l i c e \0`. |
| H2 | `person_new("Bob", 41)` from `main` (line 52) | Allocates a second `Person` struct and a separate 4-byte `name` block, containing `B o b \0`. |
| H3 | `free(bob->name)` (line 66) | Bob's 4-byte string block is released. |
| H4 | `free(bob)` (line 67) | Bob's `Person` struct is released; no Bob-owned heap block remains on the successful path. |
| H5 | `person_free_partial(alice)` (line 69) | Calls `free(p)` at line 41, releasing Alice's `Person` struct **without freeing `alice->name` first**. |
| H6 | Return from `main` | Alice's 6-byte string allocation remains allocated, but its only retained pointer was inside the now-freed struct. That heap block can no longer be reached for deallocation. |

**Logical memory map, immediately before H5:**

```text
STACK — main()
  alice ------> [Person A: name ----------> "Alice\0" (6 bytes, heap)]
  bob --------> [freed Person B]
HEAP
  Person A: allocated
  Alice name: allocated
  Person B: freed
  Bob name: freed
```

**Logical memory map, after H5:**

```text
STACK — main()
  alice: no longer designates a live Person object
HEAP
  Person A: freed
  Alice name: STILL ALLOCATED, no reachable owning pointer (6 bytes)
  Person B: freed
  Bob name: freed
```

### 2.2 Classification and causal explanation

- **Type:** *definitely lost memory leak* (expected Memcheck classification on the normal successful path).
- **Leaked object:** the separate `char` array allocated by `malloc(len + 1)` at `heap_example.c:21`, during `person_new("Alice", 30)` at line 51.
- **Cause:** `person_free_partial()` frees only the outer `Person` at line 41. The inner `name` block is not freed beforehand. Freeing the outer struct destroys access to the only stored pointer to the inner allocation. This is **lost ownership**, not a double-free or use-after-free.
- **Expected leaked amount:** 6 bytes in one allocation (`strlen("Alice") + 1`). Actual Valgrind output must confirm the corresponding leak record and its allocation stack.
- **Independent check:** LeakSanitizer, on a source-preserving copy compiled with GCC 14.2.0 and `-fsanitize=address`, reported **6 bytes leaked in 1 allocation**, allocated at `person_new`, line 21. This corroborates the inference but is **not** a Valgrind result.

`sizeof(Person)` and the total allocation counters depend on the target architecture and environment. Do not confuse the `Person` struct allocation with the separate string allocation: the struct is freed; its string is not.

### 2.3 Expected warnings not present on the normal path

No invalid read/write or uninitialized-value use is expected from the shown successful path. Both `Person` fields are initialized before they are printed, and each string receives a terminating `\0`. The exact Memcheck log, rather than this expectation, is the final authority on reported issues.

## 3. `aliasing_example.c` — use-after-free through an alias

### 3.1 Pointer-state timeline

`make_numbers(5)` allocates a block containing five `int` elements at line 12 and initializes all five elements at lines 16–17. The initialized values are `[0, 11, 22, 33, 44]`. On return, the local `arr` pointer goes out of scope, but its **heap allocation remains live**, and its address is stored in `main`'s `a` (line 30).

```text
BEFORE free(a) — main() stack              HEAP
 a ----------------------------------┐
 b ----------------------------------+----> [0][11][22][33][44]
                         (one block; two pointer aliases)
```

At line 34, `b = a` copies an address, **not the array**. There are two pointer objects but only one allocation. The single `free(a)` at line 38 ends that allocation's lifetime for **both** aliases.

```text
AFTER free(a) — main() stack               HEAP
 a: stale/non-usable target ------X
 b: stale/non-usable target ------X   [FREED: former int[5] block]
```

### 3.2 Source-to-warning mapping

| Source line | Operation | Expected Memcheck category | Precise cause |
|---|---|---|---|
| 42 | `b[2]` passed to `printf` | **Invalid read** (typically 4 bytes if `sizeof(int) == 4`) | Reads element 2 of a block that was freed at line 38. |
| 44 | `b[3] = 1234` | **Invalid write** (typically 4 bytes) | Writes into the same freed block at element 3. |
| 45 | `b[3]` passed to `printf` | **Invalid read** (typically 4 bytes) | Reads element 3 after its allocation's lifetime has ended; the intervening write did not make the block valid again. |

Memcheck is expected to identify that the addressed bytes were **inside a block previously allocated** at `make_numbers` line 12 and **freed** at `main` line 38. On common systems with 4-byte `int`, element 2 is 8 bytes after the block start, and element 3 is 12 bytes after it. These offsets explain why an access can be *within the numerical address range of a former allocation* while still being invalid: the issue is **lifetime**, not an out-of-bounds index.

The `printf("after free(a): b=%p", (void *)b)` operation at line 40 is **not itself a read of the freed array**. It attempts to print a now-stale pointer value; this is not equivalent to dereferencing the allocation. A compiler may warn about using the pointer after `free`, while Memcheck need not emit an `Invalid read` at that print. Do not use the apparently unchanged numerical address as proof that the block remains alive.

**Independent check:** AddressSanitizer reported a **heap-use-after-free READ of size 4** at line 42, with deallocation at line 38 and allocation at line 12. AddressSanitizer aborted at the first detected invalid read; it did not independently measure the later accesses at lines 44 and 45. Those later violations are derived from source and lifetime rules, and must be compared with the complete Memcheck log.

### 3.3 What this example is *not*

- **Not a double-free:** `free(a)` occurs once on the successful path; there is no `free(b)`.
- **Not inherently a leak:** the one dynamically allocated array has been released, even though accesses continue illegally afterward.
- **Not an uninitialized-value bug:** all five elements were initialized before `free(a)`. After freeing, the contents are no longer legally accessible; an arbitrary printed integer is not evidence of an originally uninitialized element.
- **Not an out-of-bounds bug:** indices 2 and 3 are within the original 5-element range. The allocation's expired lifetime is the reason for the invalid accesses.

## 4. Critical examination of the AI explanation

### 4.1 Actual earlier AI summary

An earlier assistant explanation in this conversation stated (original French):

> “Dans `aliasing_example.c`, les pointeurs `a` et `b` référencent le même bloc du heap. Libérer ce bloc rend les accès ultérieurs invalides à travers les deux pointeurs.”

This summary correctly identified the shared allocation and the lifetime problem, but it was **incomplete and potentially misleading as a Valgrind analysis**.

### 4.2 Why it is insufficient

1. It did not identify the **three separate memory access sites** (two reads and one write) at lines 42, 44, and 45. A correct tracer must map each diagnostic to the relevant instruction.
2. Its broad wording about “later accesses” could lead the reader to mistake the `%p` pointer-value print at line 40 for a read from the **freed heap block**. Printing a pointer value and dereferencing it are distinct operations; a Valgrind `Invalid read` is tied to an actual invalid memory access.
3. It did not explicitly explain that `a` and `b` refer to **one** allocated block, so freeing via `a` is sufficient to end that block's lifetime; freeing through `b` afterward would instead be another error. The example does **not** intentionally leak this block.

### 4.3 Corrected explanation

At `b = a` (line 34), the two local pointer objects contain the same address of the heap block allocated at line 12. `free(a)` (line 38) deallocates that block. The subsequent `b[2]` read (line 42), `b[3]` write (line 44), and `b[3]` read (line 45) are **three distinct use-after-free accesses**. Their offsets remain inside the former 5-element allocation, but its lifetime has ended. The example contains invalid reads/writes, **not a second allocation, double-free, or ordinary missing-free leak**. Tool output must be used to verify how the accesses are reported in this particular build.

This correction was made by comparing the earlier AI shorthand against the source's individual expressions and the aliasing memory map from Task 0, rather than treating the assistant's first description as sufficient evidence.

## 5. Runtime Valgrind verification — to complete before submission

**The rows below must be completed using the student's actual Valgrind logs. No Valgrind output, process IDs, heap addresses, error summaries, or exact category counts have been invented.**

| Program | Source-based expectation | Actual Valgrind diagnostic / stack trace |
|---|---|---|
| `heap_example` | One `definitely lost` 6-byte `name` allocation; allocation at line 21 | **PENDING — paste matching loss record** |
| `aliasing_example` | Invalid read for `b[2]`, line 42 | **PENDING — paste matching record** |
| `aliasing_example` | Invalid write for `b[3]`, line 44 | **PENDING — paste matching record** |
| `aliasing_example` | Invalid read for `b[3]`, line 45 | **PENDING — paste matching record** |
| Both | Check for any additional warnings, including uses of uninitialized values and `ERROR SUMMARY` | **PENDING — record actual results; do not assume zero** |

After collecting the logs, compare each stack trace's `at ...`, `by ...`, allocation, and free sites to the source lines listed above. Record any discrepancy, including optimized-out accesses, extra diagnostics, or a run that exits early. Do not claim the report is fully verified until this comparison is done.

## 6. References

- Valgrind, *Memcheck: a memory error detector*: https://valgrind.org/docs/manual/mc-manual.html
- CERT C, *MEM30-C — Do not access freed memory*: https://wiki.sei.cmu.edu/confluence/display/c/MEM30-C.+Do+not+access+freed+memory
- Repository source: https://github.com/hbtn-edu/ai_memory_visualizer_valgrind_tracer
- Task 0 memory model: `analysis/memory_maps.md`
