#include <stdio.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 8
static long num_steps = 100000;
double step;

int main() {
    int i;
    double pi;
    double sum[NUM_THREADS];
    step = 1.0/(double) num_steps;

    clock_t start_time = clock();
    double sum_serial = 0.0;
    for(i = 0; i < num_steps; i++){
        double x = (i+0.5)*step;
        sum_serial += 4.0/(1.0+x*x);
    }
    pi = sum_serial / num_steps;
    clock_t end_time = clock();
    double serial_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Serial version: pi = %6.12f, time = %f seconds\n", pi, serial_time);

    start_time = clock();
    #pragma omp parallel private(i) num_threads(NUM_THREADS)
    {
        int id = omp_get_thread_num();
        for(i = id, sum[id] = 0.0; i < num_steps; i += NUM_THREADS){
            double x = (i+0.5)*step;
            sum[id] += 4.0/(1.0+x*x);
        }
    }
    for(i = 1; i < NUM_THREADS; i++) 
        sum[0] += sum[i];
    pi = sum[0] / num_steps;
    end_time = clock();
    double parallel_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Parallel version: pi = %6.12f, time = %f seconds\n", pi, parallel_time);
    return 0;
}
