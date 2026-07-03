#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 50000

static int data[ARRAY_SIZE];

static void initialize_data(void)
{
    int i;

    for (i = 0; i < ARRAY_SIZE; i++)
        data[i] = i;
}

static int count_even_naive(void)
{
    int count;
    int i;
    int j;

    count = 0;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (data[j] % 2 == 0)
                count++;
        }
    }

    return count;
}

static int count_even_single_pass(void)
{
    int count;
    int i;

    count = 0;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (data[i] % 2 == 0)
            count++;
    }

    return count;
}

int main(void)
{
    unsigned long checksum;
    clock_t total_start;
    clock_t total_end;
    clock_t build_start;
    clock_t build_end;
    clock_t process_start;
    clock_t process_end;
    clock_t reduce_start;
    clock_t reduce_end;
    double total_seconds;
    double build_seconds;
    double process_seconds;
    double reduce_seconds;

    total_start = clock();

    build_start = clock();
    build_dataset();
    build_end = clock();

    process_start = clock();
    process_dataset();
    process_end = clock();

    reduce_start = clock();
    checksum = reduce_checksum();
    reduce_end = clock();

    total_end = clock();

    if (checksum == 0ul)
        printf("impossible\n");

    total_seconds = (double)(total_end - total_start) / (double)CLOCKS_PER_SEC;
    build_seconds = (double)(build_end - build_start) / (double)CLOCKS_PER_SEC;
    process_seconds = (double)(process_end - process_start) / (double)CLOCKS_PER_SEC;
    reduce_seconds = (double)(reduce_end - reduce_start) / (double)CLOCKS_PER_SEC;

    printf("TOTAL seconds: %.6f\n", total_seconds);
    printf("BUILD_DATA seconds: %.6f\n", build_seconds);
    printf("PROCESS seconds: %.6f\n", process_seconds);
    printf("REDUCE seconds: %.6f\n", reduce_seconds);

    return 0;
}

