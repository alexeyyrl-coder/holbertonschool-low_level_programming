Here is what I have learned through my exercises and reading.

Processor computations consume both energy and time, which—on a larger scale—can have significant repercussions.
A program that takes 0.0005 seconds to execute instead of 0.00002 seconds consumes far more energy and requires more processing time. For a small program, this is negligible; however, in the context of a large website, a video game, or a software application, these factors can accumulate, leading to performance issues, excessive energy consumption, or even system crashes if multiple resource-intensive loops are triggered simultaneously.

In short, failing to properly account for computation time can lead to problems such as:
faster battery drain,
longer execution times,
and higher energy consumption.

To address this, the first step is to take measurements using `clock()` and convert the result using `CLOCKS_PER_SEC`.
This requires including the `time.h` library and using the appropriate functions to measure the execution time of various routines.

By running several tests, I was able to calculate an average to determine the performance difference between the two programs presented in the course.

For this "green tech" project, I compared two scripts:
the "naive" approach and the "single-pass" approach.

Here is the performance difference between the two:
the naive approach takes 1.030335 seconds,
while the single-pass approach takes 0.000036 seconds.

This is a massive difference—the single-pass approach is 100,000 times faster than the naive version.
This serves as a clear example of the impact that optimizing code can have compared to unoptimized (naive) code. From this, I learned how to use the `time.h` library to measure a program's execution time and create more optimized code.

`time.h` – Included via `#include <time.h>`, this library provides access to the functions covered in the exercises. 
`clock_t` – A specific variable type.
`clock()` – A function used to retrieve the number of CPU cycles.
`CLOCKS_PER_SEC` – A constant used to convert CPU cycles into seconds (via division); it is essential for measuring program performance more easily and effectively.

Of course, my experience is limited; one cannot draw definitive conclusions based on just a few trials.
Other limitations of my experiment include:
I only used one compiler.
I was restricted to the C programming language.
I tested exclusively on my own machine.
I used only Windows with WSL (Windows Subsystem for Linux).