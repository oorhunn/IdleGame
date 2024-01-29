#include <stdio.h>
#include <omp.h>

#define MAX_THREADS 4
static long num_steps = 100000000;
double step;

int main ()
{

    int i,j;
    double pi;
    double start_time, run_time;

    step = 1.0/(double) num_steps;
    
    for (j=1;j<=MAX_THREADS ;j++) {
        omp_set_num_threads(j);
        start_time = omp_get_wtime();
        #pragma omp parallel
        {
            double sum = 0.0;
            int i;
            int id = omp_get_thread_num();
            int numthreads = omp_get_num_threads();
            double x;
            if (id == 0) 
                printf(" num_threads = %d",numthreads);
            for (i=id;i< num_steps; i+=numthreads){
                x = ( i + 0.5 ) * step;

                    sum = sum + 4.0 / ( 1.0 + x * x );
            }
            sum = sum * step;
            #pragma omp atomic
                pi += sum;
            
        }

        run_time = omp_get_wtime() - start_time;
        printf("\n pi is %f in %f seconds %d thrds \n",pi,run_time,j);
    }
    
}	  
