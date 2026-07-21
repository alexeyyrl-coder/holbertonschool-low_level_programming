# AI Memory Visualizer

## Methodology

This analysis was produced by reading the source code, compiling the
programs with the provided Makefile, executing the available programs
normally, and constructing explicit memory maps for important execution
points.

The analysis distinguishes:

- stack frames and local variables;
- dynamically allocated heap objects;
- pointer values and pointer aliases;
- object lifetime;
- ownership and deallocation responsibility.

AI assistance was used to generate initial explanations and memory-map
hypotheses. These explanations were then reviewed against the actual C
source code and compiler output. AI output was treated as a hypothesis,
not as authoritative evidence.

## Build Observation

The provided Makefile uses the following compiler flags:

```text
-Wall -Wextra -Werror -pedantic -std=gnu89 -g

The build succeeded for some of the programs, including
heap_example.c. However, compilation of aliasing_example.c failed on
the current GCC version.

The compiler reported that pointer b was used after the call to
free(a). The warning category was:

-Wuse-after-free

Because the Makefile uses -Werror, this warning was promoted to a
compilation error.

The compiler identified the later uses of b, including the reads and
writes through b[2] and b[3]. This build failure is consistent with
the intentional memory error present in the source code. The source code
was not patched because this task requires analysis rather than
correction.

The most important accesses identified by the compiler were:

free(a);
printf("reading b[2]=%d\n", b[2]);
b[3] = 1234;
printf("wrote b[3]=%d\n", b[3]);

The compiler output is evidence that the lifetime of the allocation ends
at free(a), while b is still later used as if the allocation remained
valid.

Analysis of stack_example.c
Program Purpose

stack_example.c demonstrates recursive function calls, stack frames,
local variables, pointer aliases, and local-variable lifetimes.

The program begins in main and calls:

walk_stack(0, 3);

walk_stack recursively calls itself with increasing values of depth
until depth reaches max_depth.

The active recursion levels are therefore:

walk_stack(0, 3)
walk_stack(1, 3)
walk_stack(2, 3)
walk_stack(3, 3)

Each call is a separate function invocation and therefore has a separate
stack frame.

Memory State 1: Entry into main

At the beginning, only the main stack frame is active.

STACK

+-----------------------------+
| main frame                  |
+-----------------------------+

HEAP

No heap allocation

No dynamic memory is allocated by this program.

Memory State 2: Entry into walk_stack(0, 3)

The first walk_stack frame contains its own parameters and local
variable.

STACK

+-----------------------------+
| walk_stack frame            |
| depth = 0                   |
| max_depth = 3               |
| marker = 0                  |
+-----------------------------+
| main frame                  |
+-----------------------------+

HEAP

No heap allocation

The lifetime of marker begins when this invocation of walk_stack
starts and ends when this specific invocation returns.

Memory State 3: Inside dump_frame("enter", 0)

walk_stack calls dump_frame. This creates a temporary additional
stack frame containing:

int local_int = 100 + depth;
char local_buf[16];
int *p_local = &local_int;

For depth == 0, the state is approximately:

STACK

+----------------------------------+
| dump_frame frame                 |
| label -> "enter"                 |
| depth = 0                        |
| local_int = 100                  |
| local_buf = "A"                  |
| p_local --------+                |
|                 |                |
|                 +-> local_int    |
+----------------------------------+
| walk_stack frame                 |
| depth = 0                        |
| max_depth = 3                    |
| marker = 0                       |
+----------------------------------+
| main frame                       |
+----------------------------------+

HEAP

No heap allocation

p_local is an alias for local_int. It contains the address of
local_int; it does not contain a separate integer object.

The following relationship is therefore true during this call:

p_local == &local_int

When dump_frame returns, its entire frame ends. The lifetimes of
local_int, local_buf, and p_local also end.

No pointer to these local objects is returned, so the caller does not
retain access to them.

Memory State 4: Recursive Calls

After the first call to dump_frame returns, walk_stack calls itself
recursively.

At the deepest recursive level, four walk_stack frames exist
simultaneously:

STACK

+-----------------------------+
| walk_stack depth = 3        |
| marker = 30                 |
| max_depth = 3               |
+-----------------------------+
| walk_stack depth = 2        |
| marker = 20                 |
| max_depth = 3               |
+-----------------------------+
| walk_stack depth = 1        |
| marker = 10                 |
| max_depth = 3               |
+-----------------------------+
| walk_stack depth = 0        |
| marker = 0                  |
| max_depth = 3               |
+-----------------------------+
| main frame                  |
+-----------------------------+

HEAP

No heap allocation

Each marker is a different object. Although every variable is named
marker, the variables belong to different function invocations and
therefore have independent storage and lifetimes.

When dump_frame("enter", 3) is executing, its temporary frame is added
above the four walk_stack frames. When that function returns, only the
four recursive walk_stack frames remain.

Memory State 5: Recursion Unwinding

At depth == 3, the condition:

if (depth < max_depth)

is false, so no additional recursive call occurs.

The calls then return in reverse order:

walk_stack(3) returns
walk_stack(2) resumes and returns
walk_stack(1) resumes and returns
walk_stack(0) resumes and returns
main resumes

Before each walk_stack call returns, it calls:

dump_frame("exit", depth);

Each exit call creates a new temporary dump_frame frame. It is not the
same frame that was used during the earlier "enter" call.

The implementation may reuse similar stack addresses for separate calls
because the earlier local variables no longer exist. Address reuse does
not mean the variables have remained alive.

Lifetime Summary
Object	Storage	Lifetime
marker	Stack	One specific walk_stack invocation
depth	Stack	One specific function invocation
local_int	Stack	One call to dump_frame
local_buf	Stack	One call to dump_frame
p_local	Stack	One call to dump_frame
Dynamic allocation	Heap	None in this program
Analysis of aliasing_example.c
Program Purpose

aliasing_example.c demonstrates:

dynamic allocation;
pointer aliasing;
allocation ownership;
dangling pointers;
use-after-free reads;
use-after-free writes.
Memory State 1: Beginning of main

At the beginning of main, the pointers do not refer to any allocated
object.

STACK

+-----------------------------+
| main frame                  |
| a = NULL                    |
| b = NULL                    |
| n = 5                       |
+-----------------------------+

HEAP

No heap allocation
Memory State 2: Inside make_numbers

The function allocates enough memory for five integers:

arr = malloc((size_t)n * sizeof(int));

During the function call, the memory state is:

STACK

+--------------------------------+
| make_numbers frame             |
| n = 5                          |
| i = current loop index         |
| arr ------------------------+   |
+-----------------------------|--+
| main frame                  |   |
| a = NULL                    |   |
| b = NULL                    |   |
| n = 5                       |   |
+-----------------------------|--+
                              |
HEAP                          v

+--------------------------------+
| allocated int[5]               |
| [0, 11, 22, 33, 44]           |
+--------------------------------+

The variable arr is stored in the make_numbers stack frame. The
integer array is stored in a separate heap allocation.

When make_numbers returns, its local pointer variable arr ceases to
exist. However, the heap allocation remains alive because it has not
been freed.

The allocation address is returned and stored in a.

Memory State 3: After a = make_numbers(n)
STACK

+-----------------------------+
| main frame                  |
| a ----------------------+   |
| b = NULL                |   |
| n = 5                   |   |
+-------------------------|---+
                          |
HEAP                      v

+-----------------------------+
| allocated int[5]            |
| [0, 11, 22, 33, 44]        |
+-----------------------------+

At this point, the allocation is valid and may be accessed through a.

Memory State 4: After b = a

The statement:

b = a;

copies the pointer value. It does not duplicate the heap allocation.

STACK

+-----------------------------+
| main frame                  |
| a ----------------------+   |
| b ----------------------+|  |
| n = 5                   ||  |
+-------------------------||--+
                          ||
HEAP                      vv

+-----------------------------+
| one allocated int[5]        |
| [0, 11, 22, 33, 44]        |
+-----------------------------+

Both pointers are aliases for the same object:

a == b

A modification through a would be visible through b, and a
modification through b would be visible through a.

There are two pointer variables, but only one dynamically allocated
array.

Ownership Before free

The code does not create a formal ownership system, but a acts as the
pointer used to release the allocation.

b is a non-owning alias. It provides access to the same allocation,
but it must not independently free the allocation after a has already
freed it.

Only one successful free must be applied to this allocation.

Memory State 5: After free(a)

The statement:

free(a);

ends the lifetime of the heap allocation.

It does not automatically assign NULL to either pointer.

The conceptual state becomes:

STACK

+---------------------------------+
| main frame                      |
| a = old allocation address      |
|     dangling                    |
| b = old allocation address      |
|     dangling                    |
| n = 5                           |
+---------------------------------+

HEAP

+---------------------------------+
| former int[5] allocation        |
| lifetime ended by free(a)       |
| no longer valid to access       |
+---------------------------------+

Both pointers become dangling pointers because both contained the
address of the same allocation.

The important event is not that the variable named a was used as the
argument to free. The important event is that the heap object shared
by a and b was deallocated.

Invalid Read

The program later evaluates:

b[2]

Array indexing is equivalent to pointer arithmetic and dereferencing:

b[2] == *(b + 2)

This operation attempts to read an integer from an allocation whose
lifetime has already ended.

This is a use-after-free and an invalid read.

A precise explanation is:

b still contains the former address of the array, but the array
object was deallocated by free(a). Evaluating b[2] dereferences a
dangling pointer and attempts to read outside the lifetime of a valid
object.

It is not sufficient to say that "b is wrong."

Invalid Write

The program also performs:

b[3] = 1234;

This attempts to write into the same deallocated allocation.

This is a use-after-free and an invalid write.

The write may:

appear to succeed;
overwrite allocator metadata;
overwrite another later allocation;
cause a crash;
produce different behavior on another execution.

The fact that the program may continue running does not make the access
valid. Its behavior is undefined.

The later expression:

printf("wrote b[3]=%d\n", b[3]);

performs another invalid read through the dangling pointer.

Compiler Evidence

The current compiler detected these accesses statically and reported
that pointer b was used after the call to free(a).

The compiler also indicated the source location of the original
deallocation. This creates a causal chain:

a receives heap address
        |
        v
b = a creates an alias
        |
        v
free(a) ends the allocation lifetime
        |
        v
b still contains the old address
        |
        v
b[2] performs an invalid read
b[3] performs an invalid write
Optional Analysis of heap_example.c
Observed Execution

A normal execution produced output similar to:

heap_example: allocations and a deliberate leak
alice=0x5d74b3f856b0 name=0x5d74b3f856d0 age=30
bob=0x5d74b3f856f0 name=0x5d74b3f85710 age=41

The exact addresses are specific to one execution and may change on
later executions.

The important observation is that each structure address differs from
its corresponding name address.

This confirms that each Person uses two distinct heap allocations:

one allocation for the Person structure;
one allocation for the character string.
Memory State After Both Persons Are Created
STACK

+----------------------------------+
| main frame                       |
| alice -----------------------+   |
| bob ----------------------+   |  |
+---------------------------|---|--+
                            |   |
HEAP                        |   |
                            |   v
                            |  +-------------------+
                            |  | Person alice      |
                            |  | age = 30          |
                            |  | name ---------+   |
                            |  +---------------|---+
                            |                  |
                            |                  v
                            |  +-------------------+
                            |  | "Alice\0"         |
                            |  +-------------------+
                            |
                            v
                       +-------------------+
                       | Person bob        |
                       | age = 41          |
                       | name ---------+   |
                       +---------------|---+
                                       |
                                       v
                            +-------------------+
                            | "Bob\0"           |
                            +-------------------+

The pointer variable alice is on the stack. The Person structure it
points to is on the heap. The character data referenced by
alice->name is in a second heap allocation.

The same structure applies to bob.

Correct Deallocation of bob

The program releases bob using:

free(bob->name);
free(bob);

The string allocation is freed first, followed by the structure that
contains the pointer to that string.

After these calls, both heap objects associated with bob have ended
their lifetimes.

Partial Deallocation of alice

The program calls:

person_free_partial(alice);

The function only performs:

free(p);

This frees the Person structure but does not free the separate
allocation referenced by p->name.

Before the structure is freed, the state is:

alice -> Person structure -> "Alice\0"

After only the structure is freed:

Person structure: freed
"Alice\0" allocation: still allocated

The address of the string was stored inside the now-freed structure.
Once that structure is released, the program loses its remaining path
to the string allocation.

This creates a memory leak.

The leaked object is not the local pointer variable alice. The leaked
object is the separately allocated character array containing
"Alice\0".

AI Explanation Review and Correction
Initial AI Explanation

An initial AI explanation stated:

Only a becomes invalid after free(a). Pointer b remains valid
because free was called with a, not with b.

Why This Explanation Was Incorrect

This explanation incorrectly treats pointer variables as if each pointer
owned an independent memory block.

Before the call to free, the statement:

b = a;

causes both pointers to contain the same allocation address.

The state is:

a ----+
      +----> one heap allocation
b ----+

free(a) deallocates the heap object, not the stack variable a.

Since b refers to the same heap object, the end of that object's
lifetime also invalidates accesses through b.

The validity of b does not depend on whether its own variable name was
passed to free. It depends on whether the object it designates is
still alive.

Corrected Explanation

After free(a):

the dynamically allocated integer array no longer exists as a valid C
object;
a still contains an obsolete address and is dangling;
b contains the same obsolete address and is also dangling;
reading b[2] is an invalid read after free;
writing b[3] is an invalid write after free;
calling free(b) afterward would attempt to free the same allocation
a second time.

Another incomplete AI assumption was that free(a) automatically sets
a to NULL. It does not. If the program wants the pointer variable to
contain NULL, it must perform a separate assignment:

free(a);
a = NULL;

However, setting only a to NULL would not automatically update the
alias b. The program would still need to manage every alias correctly.

Conclusion

These programs demonstrate that pointer correctness depends on object
lifetime, not only on pointer syntax.

The main conclusions are:

Every function call has its own stack frame and its own local
variables.
Local stack objects stop existing when their function invocation
returns.
Heap objects remain alive after the allocating function returns, but
only until they are explicitly freed.
Pointer assignment copies an address; it does not duplicate the
pointed-to object.
Multiple aliases become invalid when their shared object is freed.
free ends the lifetime of an allocation but does not automatically
set pointer variables to NULL.
A structure and the data referenced by its pointer members may require
separate allocations and separate deallocations.
A program may appear to continue after an invalid access, but the
operation remains undefined.
Compiler diagnostics and AI explanations must be checked against the
actual object lifetime and memory relationships in the source code.
