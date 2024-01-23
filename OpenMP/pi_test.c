
#include <stdio.h>
#include <omp.h>

double step;
static long num_steps = 100000;
int main () {
    int i; double x, pi, sum = 0.0;

    step = 1.0 / (double) num_steps;

    int aa = omp_get_num_threads();

    // for (i = 0; i < num_steps; i++) {
    //     x = (i + 0.5) * step;
    //     sum = sum + 4.0 / (1.0 + x * x);
    // }
    // pi = step * sum;
    printf("aa %d \n", aa);

    return 0;
}