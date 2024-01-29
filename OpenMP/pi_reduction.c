#include <stdio.h>
#include <omp.h>

#define MAX_THREADS 4

static long num_steps = 100000000;
double step;

int main ()
{
    int i;
    double x, pi, sum = 0.0;
    double start_time, run_time;

    start_time = omp_get_wtime();


    step = 1.0 / (double)num_steps;
    omp_set_num_threads(MAX_THREADS);
    int numthreads = omp_get_num_threads();
    #pragma omp parallel private(x) reduction(+ : sum)
    {
        #pragma omp for schedule(dynamic, 10000)
            for (i=0;i< num_steps; i++) {
                x = (i + 0.5) * step;
                sum = sum + 4.0 / (1.0 + x * x);
                // printf("thread is --> %d \n", id);
                // printf("i is --> %d \n", i);

            }
        
    }
    
    pi = step * sum;
    run_time = omp_get_wtime() - start_time;

    printf("pi is %f \n", pi);
    printf("runtime is %f \n", run_time);
    
}	  
