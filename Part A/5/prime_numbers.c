#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 100000;
    int prime_count;

    // Serial version
    clock_t start_time = clock();
    prime_count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }
    clock_t end_time = clock();
    double serial_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Serial version: Primes found = %d, time = %f seconds\n", prime_count, serial_time);

    // Parallel version
    start_time = clock();
    prime_count = 0;
    #pragma omp parallel for reduction(+:prime_count) schedule(dynamic)
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }
    end_time = clock();
    double parallel_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Parallel version: Primes found = %d, time = %f seconds\n", prime_count, parallel_time);

    return 0;
}
