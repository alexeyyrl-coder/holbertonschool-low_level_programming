# AI Memory Visualizer — Step-by-Step Memory Maps

**Project:** `ai_memory_visualizer_valgrind_tracer`  
**Source programs:** `programs/stack_example.c`, `programs/aliasing_example.c`  
**Scope:** Task 0 (mandatory programs). The optional `heap_example.c` is not included.  
**Method:** Read the C source, identify lifetime transitions, construct memory maps, compare with observed output, and critically review the AI's explanation.

> **Evidence note:** The `stack_example` addresses below come from an actual run supplied by the student on 2026-11-23. The `aliasing_example` maps are derived from the source code and were also compared against one separate run in the assistant's GCC environment (see §3.4); **no output from the student's machine was provided** for that program. Printed values after `free()` are not reliable evidence of valid memory access.

## 1. Fundamental memory model

- **Stack (typical implementation):** activation records for active function calls, including automatic local variables and parameters. When an invocation returns, its non-VLA automatic objects' lifetimes end. Actual register placement and frame layout are implementation-dependent; the maps show the *logical* objects and observed addresses, not a compiler-guaranteed layout.
- **Heap:** dynamically allocated objects obtained through `malloc`. An allocation remains alive after the function that requested it returns, until the allocation is freed. A pointer variable is not the same object as the allocation it points to.
- **Pointer value versus pointer object's address:** `p_local` evaluates to the address of its target; `&p_local` would be the address of the pointer variable itself. The example prints the former, not the latter.
- **Ownership:** C pointers do not automatically encode ownership. The programmer must establish which code will release an allocation and must avoid using aliases after that release.

## 2. `stack_example.c` — recursion and stack frames

### 2.1 Relevant functions and lifetime boundaries

- `main()` invokes `walk_stack(0, 3)`.
- Each `walk_stack(depth, max_depth)` invocation has its own parameters and its own automatic `marker = depth * 10`.
- `walk_stack` calls `dump_frame("enter", depth)`, then (if `depth < max_depth`) calls the next `walk_stack`, then calls `dump_frame("exit", depth)`.
- **Each** invocation of `dump_frame` has new automatic objects: `local_int = 100 + depth`, `local_buf[16]`, and `p_local = &local_int`. Its `label` and `depth` parameters are also local to that invocation.
- Each `dump_frame` invocation ends **before** its caller continues to the next statement. Its local objects do not survive until the matching `exit` print. At `exit`, `dump_frame` is called *again* and creates new objects.
- No `malloc` is called; there are no dynamically allocated blocks to draw for this program.

### 2.2 Observed values and addresses

These addresses are **observed in one run only**. Address-space layout may change on another run.

| `depth` | `marker` | `&marker` | `local_int` during `enter` | `&local_int` during `enter` | `local_buf` address | `local_buf[0]` |
|---:|---:|---|---:|---|---|---|
| 0 | 0  | `0x7fffab9b97a4` | 100 | `0x7fffab9b9754` | `0x7fffab9b9760` | `A` |
| 1 | 10 | `0x7fffab9b9774` | 101 | `0x7fffab9b9724` | `0x7fffab9b9730` | `B` |
| 2 | 20 | `0x7fffab9b9744` | 102 | `0x7fffab9b96f4` | `0x7fffab9b9700` | `C` |
| 3 | 30 | `0x7fffab9b9714` | 103 | `0x7fffab9b96c4` | `0x7fffab9b96d0` | `D` |

For each `enter` line, the printed `p_local` value matches the printed `&local_int`. This proves that `p_local` **points to** `local_int`, not that they are the same object. In this run, neighboring `&marker` values differ by `0x30` (48) bytes, showing a regular pattern in the compiler's placement of these particular objects. It does **not** establish that every stack frame is exactly 48 bytes long.

The `exit` lines repeat the same displayed `&local_int` and `local_buf` addresses for each depth. These are **new objects in new calls** to `dump_frame`, occupying reusable storage; they are not the original `enter` objects surviving across recursion.

### 2.3 Step-by-step logical memory maps

Notation: `W0` means `walk_stack(depth=0, max_depth=3)`, and `D3-enter` means the `dump_frame` invocation printing `enter` for depth 3. `main` is active throughout the nested calls. Frames below are listed from caller to callee, not as a byte-accurate memory layout.

**T0 — Enter `W0`, before calling `dump_frame`:**

```text
STACK (active invocations)
  main
  W0: depth=0, max_depth=3, marker=0 @ 0x7fffab9b97a4
HEAP: no allocations
```

**T1 — While `D0-enter` prints `[enter] depth=0`:**

```text
STACK
  main
  W0: marker=0 @ 0x7fffab9b97a4  [still alive]
  D0-enter:
      local_int=100 @ 0x7fffab9b9754
      local_buf[0]='A', local_buf[1]='\0'; array starts @ 0x7fffab9b9760
      p_local holds 0x7fffab9b9754 ──> local_int
HEAP: no allocations
```

When `D0-enter` returns, its `local_int`, `local_buf`, and `p_local` objects end their lifetimes, while `W0.marker` remains alive. The other elements of `local_buf` were not initialized by this function; no assumptions should be made about their values.

**T2 — On entry at depths 1 and 2:**

```text
STACK after entering W2, before its dump_frame call
  main
  W0: marker=0  @ 0x7fffab9b97a4
  W1: marker=10 @ 0x7fffab9b9774
  W2: marker=20 @ 0x7fffab9b9744
HEAP: no allocations
```

The earlier calls have not returned; their `marker` objects therefore still exist.

**T3 — At the instant `[enter] depth=3` is being printed:**

```text
STACK
  main
  W0: marker=0  @ 0x7fffab9b97a4 [alive]
  W1: marker=10 @ 0x7fffab9b9774 [alive]
  W2: marker=20 @ 0x7fffab9b9744 [alive]
  W3: marker=30 @ 0x7fffab9b9714 [alive]
  D3-enter:
      local_int=103 @ 0x7fffab9b96c4
      local_buf[0]='D', local_buf[1]='\0' @ 0x7fffab9b96d0 (start)
      p_local holds 0x7fffab9b96c4 ──> local_int
HEAP: no allocations
```

There are **four live `marker` objects** at this point, and also a currently active `dump_frame` invocation. Immediately after `D3-enter` returns, its locals cease to exist. The condition `depth < max_depth` is false for `depth=3`, so no further recursive `walk_stack` call occurs.

**T4 — During `[exit] depth=3`:**

```text
STACK
  main -> W0 -> W1 -> W2 -> W3 -> D3-exit
  W0.marker=0; W1.marker=10; W2.marker=20; W3.marker=30
  D3-exit: NEW local_int=103 and NEW local_buf; NEW p_local -> NEW local_int
HEAP: no allocations
```

`D3-exit` can receive the same addresses previously printed by `D3-enter`, without the old objects having remained alive. Once `D3-exit` returns, `W3` returns and its `marker` lifetime ends.

**T5 — Return sequence:**

```text
D2-exit executes with W0, W1 and W2 still active; then W2 returns.
D1-exit executes with W0 and W1 still active; then W1 returns.
D0-exit executes with W0 still active; then W0 returns to main.
```

Thus the output order is `enter 0, 1, 2, 3`, followed by `exit 3, 2, 1, 0`. Matching numeric addresses on `enter`/`exit` do not imply that the same `dump_frame` local objects survived.

### 2.4 Conclusions for the stack example

- Recursion creates distinct active `walk_stack` invocations; `marker` belongs to each invocation individually.
- `dump_frame` uses short-lived automatic local objects. The variable `p_local` itself is distinct from `local_int`, even though its **value** is `&local_int`.
- Reused addresses demonstrate that *location* and *object lifetime* are different concepts.
- The source performs no dynamic allocations; the heap is not involved in these maps.

## 3. `aliasing_example.c` — heap allocation, aliases, and dangling pointers

### 3.1 Creation and initialization

The normal successful execution path starts in `main` with local pointer objects `a = NULL`, `b = NULL`, and integer `n = 5`. Then `a = make_numbers(n)` calls a function with its own parameter `n`, local `i`, and local pointer `arr`.

Inside `make_numbers`, `malloc((size_t)n * sizeof(int))` allocates **five contiguous `int` elements**, provided the allocation succeeds. The initialization loop stores `0`, `11`, `22`, `33`, and `44`.

**A0 — During `make_numbers`, after initialization, before `return arr`:**

```text
STACK
  main: a=NULL; b=NULL; n=5
  make_numbers: n=5; i=5; arr ───────────────┐
HEAP                                           v
  allocation H, 5 * sizeof(int) bytes: [0][11][22][33][44]
```

`arr` is a local pointer object; its **target** is in the heap. When `make_numbers` returns, the local `arr` object ceases to exist, **but allocation H is still alive**. The returned address is stored in `main.a`.

**A1 — After `a = make_numbers(n)`, before `b = a`:**

```text
STACK (main)
  a ─────────────────┐
  b = NULL           │
  n = 5              │
HEAP                 v
  H (allocated): [0][11][22][33][44]
```

**A2 — After `b = a`:**

```text
STACK (main)
  a ──────────────┐
  b ──────────────┤  SAME pointer value; two distinct pointer objects
  n = 5           │
HEAP              v
  H (allocated): [0][11][22][33][44]
                   ^ index 2 = 22, index 3 = 33
```

`b = a` copies the pointer **value**, not the array. Thus writing to `b[3]` while H remains alive would modify the same element visible through `a[3]`. This is **aliasing**.

### 3.2 Deallocation and invalid accesses

**A3 — Immediately after `free(a)`:**

```text
STACK (main)
  a: pointer object still exists; no valid allocated target
  b: pointer object still exists; no valid allocated target
  n = 5
HEAP
  H: FREED — its lifetime has ended; contents are no longer accessible
```

`free(a)` releases allocation H **once**. It does not separately free `a` or `b` (which are local pointer objects), and it does not set either to `NULL`. Both aliases no longer designate a live allocated object. Under the C abstract machine, pointer values to an object whose lifetime has ended are indeterminate; do not depend on reading or printing those stale values. On common implementations, they may still *appear* to contain the old numerical address.

**A4 — Subsequent source operations:**

| Operation | Analysis |
|---|---|
| `printf(..., (void *)b)` after the free | Printing an apparently unchanged pointer value is not proof of a live allocation; stale pointer values must not be relied on. |
| `printf("  reading b[2]=%d\n", b[2])` | **Use-after-free / invalid read:** tries to read an `int` from released H. Behavior is undefined. |
| `b[3] = 1234` | **Use-after-free / invalid write:** tries to write to released H. Behavior is undefined. |
| `printf("  wrote b[3]=%d\n", b[3])` | Another **invalid read** of released H. |

No specific printed values, crash, or absence of crash should be predicted for the use-after-free instructions: undefined behavior means the C standard does not guarantee their outcome. A debugger or Valgrind may expose invalid operations, but Task 0 instructs running the programs normally first.

### 3.3 Ownership and lifetime conclusions

- The allocated array remains alive after `make_numbers` returns because it belongs to the heap, not the callee's stack frame.
- `a` and `b` are separate local pointer objects containing the same address before deallocation; neither pointer inherently encodes ownership.
- The single call `free(a)` ends the lifetime of their common target H. It would be wrong to infer that `b` retains its own independent allocation.
- The program's intended error is **use-after-free**, not a double-free. The source frees H once and makes later invalid accesses to it.
- In the successful path, there is no intended heap leak from H: its storage is freed. That does not make the later accesses valid.

### 3.4 Runtime verification to complete

Run `./aliasing_example` normally from `programs/`. Check that the printed `a` and `b` addresses match **before** `free(a)`, and note whether the program prints further lines or terminates. Do **not** infer from the observed numbers after the free that reading or writing freed memory is safe.

**Independent assistant-environment test (not the student's run):** With a recent GCC, the bundle's `-Werror` made the intentionally invalid uses after `free(a)` fail compilation with `-Werror=use-after-free`. To observe runtime behavior without editing the source, the test downgraded only that diagnostic to a warning (`-Wno-error=use-after-free`) and retained the remaining supplied compilation flags. That test printed identical `a`/`b` addresses before freeing, `a[2]=22` and `b[2]=22`, followed by a stale pointer display, `reading b[2]=1229040097`, and `wrote b[3]=1234`. It exited with code 0 **in that particular run only**. The value `1229040097` is **not** an expected result; the post-free operations are undefined behavior. This local reproduction does not substitute for running the provided Makefile in the student's own environment.

**Student's observed terminal output:** _Not provided yet; paste the actual output here before submission, or explicitly state the compiler diagnostics if the provided Makefile rejects the deliberately unsafe code._

## 4. Critical review of AI-assisted analysis

### 4.1 Example of an incomplete AI explanation

**Earlier AI explanation (paraphrased):** At `enter depth=3`, the active recursion is represented as four `walk_stack` levels, each with its own `marker`.

**Why that account was incomplete:** Those four frames are indeed present, but that simplified map omitted the concurrently active `dump_frame("enter", 3)` invocation where the output is generated. It also did not specify that `local_int`, `local_buf`, and `p_local` from each `enter` invocation die when that `dump_frame` call returns. Without those details, a reader could incorrectly think that the `local_int` printed later at `exit depth=3` is the same long-lived object.

**Correction:** At the instant the `enter depth=3` line is printed, `main`, four `walk_stack` invocations, and one `dump_frame` invocation are logically active. `dump_frame` has its own temporary locals. The matching `exit depth=3` output comes from a **new invocation** of `dump_frame`, even if both invocations reuse the same stack addresses. The observations support *address reuse*, not *object persistence*.

### 4.2 Additional detail that a simplified AI diagram can hide

The statement `p_local = &local_int` does **not** place `p_local` and `local_int` at one address. The **value stored in** `p_local` equals `&local_int`; the pointer variable `p_local` has its own storage. Since the program does not print `&p_local`, its address cannot be inferred precisely from the supplied terminal output. The corrected memory map draws an arrow from `p_local` to `local_int` rather than merging the two variables.

### 4.3 Evidence versus inference

- **Observed from supplied output:** values and addresses in the table; `enter`/`exit` sequence; repeated printed addresses.
- **Derived from source and C lifetime rules:** distinct local objects on distinct invocations; `dump_frame` locals die at function return; heap allocation persists after `make_numbers` returns; `b = a` creates an alias; `free(a)` ends H's lifetime.
- **Not guaranteed:** exact address values on another run, exact byte layout of stack frames, or values printed after use-after-free.

**Student review before submission:** Confirm that the identified AI omission matches your own reading of the earlier explanation, verify the source-to-map transitions, and replace the runtime-verification placeholder with your actual `aliasing_example` output. Do not claim independent validation until those checks have been performed.
