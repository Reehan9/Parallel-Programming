#include <omp.h>
#include <stdio.h>

int main() {
    int n = 10;  // Number of iterations
    omp_set_schedule(omp_sched_static, 2);  // Set schedule type to static with chunk size of 2

    #pragma omp parallel for schedule(runtime)
    for (int i = 0; i < n; i++) {
        int thread_num = omp_get_thread_num();
        printf("Thread %d executing iteration %d\n", thread_num, i);
    }

    return 0;
}
