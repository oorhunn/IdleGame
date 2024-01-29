#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double rand_last;
static long num_trials = 1000000000;

void seed(unsigned int seed, double min, double max) {
    srand(seed);
}

#pragma omp threadprivate(rand_last)
double random(double min, double max) {
    double rand_last = min + ((double)rand() / RAND_MAX) * (max - min);
    double rand_next = rand_last;
    return rand_next;
}


int main () {
    long i;
    long Ncirc = 0; // Initialize Ncirc to 0
    double pi, x, y;
    double r = 1.0; // Assuming r is the radius of the circle.
    double start_time, run_time;
    int num_threads;
    start_time = omp_get_wtime();

    seed(0, -r, r);
    #pragma omp parallel 
    {    num_threads = omp_get_num_threads();
        #pragma omp for private(x, y) reduction(+:Ncirc)
        for(i = 0; i < num_trials; i++)
        {
            x = random(-r, r);
            y = random(-r, r);
            if (x * x + y * y <= r * r) {
                Ncirc++;
            }
        }
    }
    
    pi = 4.0 * ((double) Ncirc / (double) num_trials);
    run_time = omp_get_wtime() - start_time;

    printf("\n %ld trials, pi is --> %f \n", num_trials, pi);
    printf("runtime is %f \n", run_time);
    printf("number of threads is %d \n", num_threads);

    
    return 0;
}
