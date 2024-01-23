
#include <stdio.h>
#include <omp.h>

void foo(int id) {
    printf("hello %d \n", id);
}

int main (){

    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        foo(ID);        
    }
    return 0;
}