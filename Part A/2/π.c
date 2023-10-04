#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 8
static long num_steps = 10000000;
double step;

int main() {
    int i;
    double pi;
    double sum[NUM_THREADS];
    step = 1.0/(double) num_steps;

    double start  = omp_get_wtime();
    double sum_serial = 0.0;
    for(i = 0; i < num_steps; i++){
        double x = (i+0.5)*step;
        sum_serial += 4.0/(1.0+x*x);
    }
    pi = sum_serial / num_steps;
    double end  = omp_get_wtime();
    
    printf("Serial version: pi = %6.12f, time = %f seconds\n", pi, end-start);

    start  = omp_get_wtime();
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
    end  = omp_get_wtime();

    printf("Parallel version: pi = %6.12f, time = %f seconds\n", pi, end-start);
    return 0;
}
