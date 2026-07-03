# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled and executed in the same benchmarking directory and on the same machine. I used the required compiler flags: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`. For the baseline program, I did not modify the source file. I executed it several times consecutively and recorded the output in `baseline_loop-metrics.md`.

For timing, the provided programs use `clock()` from `<time.h>`. The raw clock tick difference is converted to seconds by dividing by `CLOCKS_PER_SEC`. This gives CPU time used by the program rather than a direct measurement of electrical power. In the instrumentation exercise, I placed timing boundaries immediately before and after each main phase: dataset building, dataset processing, and checksum reduction. I also measured a total duration around all three phases together.

My baseline loop measurements were: `<time_1>` seconds, `<time_2>` seconds, and `<time_3>` seconds. These values were close to each other, showing that the computation is deterministic but that timing still varies slightly between runs.

## Observed Performance Differences

The baseline loop produced similar execution times across the three runs. For example, my recorded times were `<time_1>`, `<time_2>`, and `<time_3>` seconds. The fastest run was `<fastest>` seconds and the slowest run was `<slowest>` seconds. The difference is small, but it proves that one measurement alone is not enough to describe performance precisely.

In the instrumentation program, the measured total time was `<total>` seconds. The build phase took `<build>` seconds, the process phase took `<process>` seconds, and the reduce phase took `<reduce>` seconds. Based on these measurements, the phase that consumed the most time was `<slowest_phase>`. This indicates that the cost of the program is not evenly distributed across all phases.

In the algorithm comparison program, the naive algorithm took `<naive_time>` seconds, while the single-pass algorithm took `<single_pass_time>` seconds. Both algorithms produced results, but the runtime difference shows that the implementation strategy has a major impact on efficiency. The naive version performs repeated nested work, while the single-pass version scans the array once.

## Relation Between Runtime and Energy Consumption

This project does not measure real power draw in watts, so I cannot claim exact energy consumption. However, runtime is still useful as a proxy. If a program keeps the CPU active for longer, it generally requires more energy than a program that finishes sooner under similar conditions.

The measured difference between the naive algorithm and the single-pass algorithm is the clearest example. The naive implementation took `<naive_time>` seconds, while the single-pass implementation took `<single_pass_time>` seconds. Since both were executed on the same machine and with the same dataset, the shorter runtime suggests that the single-pass implementation is more energy-efficient in practice.

The instrumentation results also support this reasoning. The phase `<slowest_phase>` took `<slowest_phase_time>` seconds, which means optimization work should focus there first if the goal is to reduce runtime and indirectly reduce energy use.

## Limitations of the Experiment

The main limitation is that I measured execution time, not actual electrical power consumption. A real energy profile would require specialized tools or hardware counters. Another limitation is that `clock()` measures CPU time, not always the same thing as wall-clock time. Background system activity, CPU frequency scaling, cache state, and other processes can influence results.

The dataset size is also fixed, so these measurements describe only this specific input size. Larger or smaller inputs could change the relative importance of each phase. Finally, running each program only a few times gives a useful first observation, but more repetitions would produce a stronger benchmark.

## Practical Engineering Takeaway

The main takeaway is that efficiency decisions should be based on measurement rather than intuition. The baseline results showed small variability between runs, so repeated measurements are necessary. The instrumentation results showed where time was spent inside a multi-phase program. The algorithm comparison showed that a simpler algorithmic approach can be much faster than a naive implementation.
