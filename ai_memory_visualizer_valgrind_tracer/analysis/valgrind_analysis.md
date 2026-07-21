# Valgrind & AI Memory Tracer

## Methodology

The programs were executed under Valgrind Memcheck with debug symbols enabled.  
The following command pattern was used:

```bash
valgrind \
    --tool=memcheck \
    --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    --num-callers=20 \
    ./program_name 2>&1 | tee ../analysis/program_valgrind.log
```

The options were selected for the following reasons:

- `--tool=memcheck` enables memory-access checking.
- `--leak-check=full` provides detailed leak records and allocation stack traces.
- `--show-leak-kinds=all` displays all leak classifications.
- `--track-origins=yes` helps locate the origin of uninitialized values.
- `--num-callers=20` requests more complete stack traces.
- `tee` preserves the runtime evidence in a log while displaying it in the terminal.

The Valgrind results were checked against the source code and the memory maps produced in the previous task. The analysis focuses on the lifetime of each heap object, pointer aliases, ownership, and the exact operation that caused each warning.

## Build Observation

The provided build flags include:

```text
-Wall -Wextra -Werror -pedantic -std=gnu89 -g
```

On the current GCC version, `aliasing_example.c` is detected statically as containing a use-after-free. Because `-Werror` promotes warnings to errors, the provided Makefile can stop before producing the executable. This compiler diagnostic is consistent with the intentional defect in the program.

The source logic was not patched for this analysis. The executable used by Valgrind retained the deliberate use-after-free and included `-g`, allowing Valgrind to report source files and line numbers.

---

## Analysis of `heap_example.c`

### Runtime result

Valgrind reported:

```text
in use at exit: 6 bytes in 1 blocks
total heap usage: 5 allocs, 4 frees, 4,138 bytes allocated

6 bytes in 1 blocks are definitely lost
    by person_new (heap_example.c:21)
    by main (heap_example.c:51)

LEAK SUMMARY:
    definitely lost: 6 bytes in 1 blocks
    indirectly lost: 0 bytes in 0 blocks
    possibly lost: 0 bytes in 0 blocks
    still reachable: 0 bytes in 0 blocks

ERROR SUMMARY: 1 errors from 1 contexts
```

### Classification

| Valgrind report | Classification |
|---|---|
| `6 bytes in 1 blocks are definitely lost` | Definite memory leak |
| `ERROR SUMMARY: 1 errors from 1 contexts` | One leak context |
| No invalid read or write | No invalid access observed in this execution |
| No uninitialized-value warning | No use of uninitialized memory reported |

### Memory object involved

The leaked object is the dynamically allocated character array containing:

```text
"Alice\0"
```

This object requires six bytes:

```text
'A' 'l' 'i' 'c' 'e' '\0'
```

It is allocated in `person_new` at `heap_example.c:21`.

The leaked object is **not** the local variable `alice`, because `alice` is only a pointer stored in the stack frame of `main`. It is also not the `Person` structure itself, because `person_free_partial(alice)` calls `free(p)` and therefore deallocates that structure.

### Allocation structure

Each call to `person_new` creates two separate heap objects:

```text
Person structure
    |
    +---- name pointer ----> separately allocated character array
```

For `alice`, the relationship is:

```text
STACK

alice
  |
  v

HEAP

Person object
  age = 30
  name ---------> "Alice\0"
```

For `bob`, the program correctly performs:

```c
free(bob->name);
free(bob);
```

Both of Bob's heap objects therefore end their lifetimes correctly.

For Alice, the program performs only:

```c
person_free_partial(alice);
```

and that function performs:

```c
free(p);
```

The `Person` structure is freed, but the separate allocation referenced by `alice->name` is not freed first.

### Ownership failure

Before the structure is freed, the address of the `"Alice\0"` allocation is stored in the `name` field of the `Person` object.

After the structure is freed, that field can no longer be accessed legally. The program has lost the only valid path to the name allocation:

```text
person_new allocates "Alice\0"
        |
        v
alice->name stores its address
        |
        v
person_free_partial frees only the Person structure
        |
        v
the name allocation remains alive
        |
        v
no valid pointer remains to free it
        |
        v
definitely lost
```

This is a **memory leak due to lost ownership**.

### Interpretation of the allocation count

Valgrind reports five total allocations, although the source performs four explicit program allocations:

1. Alice's `Person` structure.
2. Alice's name.
3. Bob's `Person` structure.
4. Bob's name.

The additional allocation is consistent with an internal runtime or standard I/O allocation. Therefore, Valgrind's total heap-usage count must not automatically be interpreted as the number of explicit `malloc` calls visible in the source.

### Conclusion for `heap_example.c`

The program does not perform a use-after-free during the observed execution, but it leaks the six-byte name allocation associated with Alice. Valgrind classifies the allocation as `definitely lost` because no valid pointer remains through which it can be released.

---

## Analysis of `aliasing_example.c`

### Runtime result

Valgrind reported three distinct memory-access errors:

```text
Invalid read of size 4
    at main (aliasing_example.c:42)

Invalid write of size 4
    at main (aliasing_example.c:44)

Invalid read of size 4
    at main (aliasing_example.c:45)
```

For these accesses, Valgrind also reported that the address was inside a previously freed block:

```text
Block was alloc'd at:
    malloc
    make_numbers (aliasing_example.c:12)
    main (aliasing_example.c:30)

Block was free'd at:
    free
    main (aliasing_example.c:38)
```

The final heap summary was:

```text
in use at exit: 0 bytes in 0 blocks
total heap usage: 2 allocs, 2 frees, 4,116 bytes allocated

All heap blocks were freed -- no leaks are possible

ERROR SUMMARY: 3 errors from 3 contexts
```

### Allocation and aliasing

`make_numbers` allocates an array of five integers:

```c
arr = malloc((size_t)n * sizeof(int));
```

With four-byte integers, the allocation contains 20 bytes:

```text
index:       0    1    2    3    4
value:       0   11   22   33   44
byte offset: 0    4    8   12   16
```

After the function returns, `a` stores the allocation address.

The statement:

```c
b = a;
```

copies that address. It does not allocate or copy a second array.

```text
STACK                         HEAP

a ----------------------+
                        +----> int[5], 20-byte allocation
b ----------------------+
```

`a` and `b` are aliases for the same heap object.

### End of the allocation lifetime

The program then executes:

```c
free(a);
```

at `aliasing_example.c:38`.

This ends the lifetime of the 20-byte heap allocation. It does not automatically set `a` or `b` to `NULL`, and it does not affect only the pointer variable named `a`.

After the call:

```text
STACK

a = old address, dangling
b = same old address, dangling

HEAP

former int[5] block
lifetime ended
access no longer valid
```

Because both pointers referred to the same object, both become dangling pointers.

### Issue 1: invalid read at line 42

The program evaluates:

```c
b[2]
```

Valgrind reports:

```text
Invalid read of size 4
at main (aliasing_example.c:42)
Address ... is 8 bytes inside a block of size 20 free'd
```

The eight-byte offset is consistent with element index 2:

```text
2 * sizeof(int) = 2 * 4 = 8 bytes
```

Classification:

```text
Use-after-free
Invalid read of a four-byte int
```

Memory misuse:

`b[2]` dereferences an alias that still contains the address of an object whose lifetime ended at `free(a)`.

The fact that the runtime printed `22` does not make the access valid. The bytes happened to retain their previous contents, but reading them after deallocation is undefined behavior.

### Issue 2: invalid write at line 44

The program performs:

```c
b[3] = 1234;
```

Valgrind reports:

```text
Invalid write of size 4
at main (aliasing_example.c:44)
Address ... is 12 bytes inside a block of size 20 free'd
```

The twelve-byte offset corresponds to index 3:

```text
3 * sizeof(int) = 3 * 4 = 12 bytes
```

Classification:

```text
Use-after-free
Invalid write of a four-byte int
```

Memory misuse:

The program attempts to modify an object after its lifetime has ended. This write could corrupt allocator metadata, overwrite another allocation, appear to work, or cause a later crash.

### Issue 3: invalid read at line 45

The program then evaluates `b[3]` again while printing it:

```c
printf("  wrote b[3]=%d\n", b[3]);
```

Valgrind reports a second invalid read of size four at line 45.

Classification:

```text
Use-after-free
Invalid read after an invalid write
```

This is a separate invalid access because evaluating the argument to `printf` requires another dereference of the dangling pointer.

### Causal chain

The complete causal chain is:

```text
malloc creates a 20-byte int array
        |
        v
a receives the allocation address
        |
        v
b = a creates a second alias
        |
        v
free(a) ends the shared object's lifetime
        |
        v
a and b both become dangling
        |
        +----> b[2] causes an invalid read
        |
        +----> b[3] = 1234 causes an invalid write
        |
        +----> printing b[3] causes another invalid read
```

### Leak result

Valgrind reports:

```text
All heap blocks were freed -- no leaks are possible
```

This does **not** mean the program is memory-safe.

The array was freed exactly once, so no leak remains at program exit. However, it was accessed after being freed. Leak detection and access-validity checking are separate properties:

```text
No leak ≠ no memory error
```

### Uninitialized-memory review

No warning involving uninitialized values was reported for `aliasing_example` in this execution.

In particular, Valgrind did not report:

```text
Use of uninitialised value
```

or:

```text
Conditional jump or move depends on uninitialised value(s)
```

This is consistent with `make_numbers`, which initializes every element before returning the array.

---

## AI Explanation Review and Correction

### Incorrect AI explanation

An initial AI explanation stated:

> Only `a` becomes invalid after `free(a)`. Pointer `b` remains valid because `b` was not passed to `free`.

### Why it is incorrect

This explanation confuses pointer variables with the heap object they designate.

Before the deallocation:

```text
a ----+
      +----> one shared heap allocation
b ----+
```

`free(a)` does not destroy the stack variable `a`. It ends the lifetime of the heap allocation whose address was passed to `free`.

Since `b` contains the same address, it also loses access to a live object. Therefore, both `a` and `b` are dangling after the deallocation.

Valgrind confirms this reasoning by reporting that all three accesses through `b` occur inside the same 20-byte block previously freed at `aliasing_example.c:38`.

### Corrected explanation

The correct explanation is:

> `a` and `b` alias the same 20-byte integer array. `free(a)` ends the lifetime of that single shared allocation. Both pointers retain the old numerical address, but neither may be dereferenced afterward. The read of `b[2]`, the write to `b[3]`, and the later read of `b[3]` are all use-after-free accesses.

### Additional incomplete AI assumption

A second potentially misleading interpretation is:

> Valgrind reports five allocations in `heap_example`, so the program source must contain five explicit allocations.

This is incomplete because Valgrind counts allocations made by the process and runtime libraries, not only the explicit calls visible in the application source.

The source creates four program-owned heap objects. The extra allocation is consistent with standard I/O or runtime initialization. Analysis must therefore rely on allocation stack traces and source-code ownership, not only on the global allocation count.

---

## Final Classification Summary

| Program | Valgrind result | Classification | Memory object | Cause |
|---|---|---|---|---|
| `heap_example` | 6 bytes definitely lost | Definite memory leak | Heap string `"Alice\0"` | The containing `Person` is freed without first freeing `name`, causing lost ownership |
| `aliasing_example` line 42 | Invalid read of size 4 | Use-after-free | Element `b[2]` in the freed 20-byte array | `b` aliases the allocation freed through `a` |
| `aliasing_example` line 44 | Invalid write of size 4 | Use-after-free | Element `b[3]` in the freed array | Write occurs after the allocation lifetime ended |
| `aliasing_example` line 45 | Invalid read of size 4 | Use-after-free | Element `b[3]` in the freed array | `printf` rereads the freed memory |
| Both programs | No uninitialized warning | No issue observed | N/A | All values used in these execution paths were initialized |

## Conclusion

The Valgrind results correspond directly to concrete object-lifetime violations.

`heap_example` demonstrates a leak caused by incomplete deallocation of a compound heap object. Freeing the outer `Person` structure is insufficient because its `name` field refers to a separate allocation. Once the structure is freed, ownership of the name allocation is lost, producing a six-byte `definitely lost` leak.

`aliasing_example` demonstrates that pointer aliases share the lifetime of the same object. `b = a` creates another route to one allocation, not another allocation. Once `free(a)` ends that object's lifetime, every dereference through `b` becomes invalid. Valgrind identifies one invalid write and two invalid reads, while correctly reporting no leak.

The main lesson is that a pointer's stored address may remain numerically unchanged even after the corresponding object has ceased to exist. Correct memory reasoning must track the lifetime and ownership of the object, not merely the value stored in the pointer.
