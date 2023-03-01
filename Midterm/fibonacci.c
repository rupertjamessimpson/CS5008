/*
* File solving Fibonacci using C.
* Author: Rupert Simpson
* Semester: Spring 2023
*/

#include <stdio.h>
#include <time.h> 

#define SIZE 300
unsigned long fib_table[SIZE];

unsigned long dynamic_fib(int n) {
    if (n <= 0) {
        return fib_table[0];
    } else if (n == 1) {
        return fib_table[1];
    } else if (fib_table[n] != -1) {
        return fib_table[n];
    }

    fib_table[n] = dynamic_fib(n - 1) + dynamic_fib(n - 2);
    return fib_table[n];
}

unsigned long recursive_fib(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return recursive_fib(n - 1) + recursive_fib(n - 2);
    }
}

unsigned long iterative_fib(int n) {
    int previousNum = 0;
    int currentNum = 1;

    for (int i = 0; i < n -1; i++) {
        currentNum = previousNum + currentNum;
        previousNum = currentNum - previousNum;
    }

    return currentNum;
}

double time_dynamic_fib(int n)
{
    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
    // Perform the sort
    dynamic_fib(n);
    // Get the time after we are done
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    return (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
           (end.tv_sec - begin.tv_sec);
}

double time_iterative_fib(int n)
{
    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
    // Perform the sort
    iterative_fib(n);
    // Get the time after we are done
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    return (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
           (end.tv_sec - begin.tv_sec);
}

double time_recursive_fib(int n)
{
    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
    // Perform the sort
    recursive_fib(n);
    // Get the time after we are done
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    return (end.tv_nsec - begin.tv_nsec) / 1000000000000.0 +
           (end.tv_sec - begin.tv_sec);
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        fib_table[i] = -1;
    }
    fib_table[0] = 0;
    fib_table[1] = 1;

    int n = 10;
    double timeTaken = time_dynamic_fib(n);
    printf("\nDynamic fib took: %f seconds for %d\n", timeTaken, n);
    printf("Result: %lu\n\n", dynamic_fib(n));

    timeTaken = time_recursive_fib(n);
    printf("Recursive fib took: %f seconds for %d\n\n", timeTaken, n);
    printf("Result: %lu\n\n", recursive_fib(n));

    timeTaken = time_iterative_fib(n);
    printf("Iterative fib took: %f seconds for %d\n\n", timeTaken, n);
    printf("Result: %lu\n\n", iterative_fib(n));
}
