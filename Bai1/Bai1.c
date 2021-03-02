// OpenMP header 
#include <omp.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
int main(int argc, char* argv[]) 
{ 
    #pragma omp parallel for
    for(int i=0;i<10;i++){
        printf("%i\n",i);
    }
    printf("Hello world");
    return 0;
} 
