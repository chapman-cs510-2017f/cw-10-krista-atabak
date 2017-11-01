#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

long double *set_arrays(int array_size){

    float array[array_size];

    long double *memblock = malloc(array_size * sizeof(long double));
    
    for (int i=0; i < array_size; i++)
    {

        array[i] = i+1.1*i;


        *(memblock+i) = i+1.1*i;
    }

    return memblock;
}
void print_arrays(long double *array,const char *foo,int array_size){


   for (int i=0; i < (array_size + 3); i++)
    {

        printf("array[%d] : %Lf\t", i, array[i]);
        printf("*(memblock + %d) : %Lf\t", i, *(array+i));
        printf("foo[%d] : %c\t", i, foo[i]);
        printf("*(foo + %d) : %c\n", i, *(foo+i));
    }

}
int main(void)
{
    long double *array = set_arrays(10);
    if (array == NULL){
        fprintf(stderr, "malloc failed\n");
        return -1;
    }
    
   const char *foo = "Foo bar .";

   print_arrays(array,foo,10);

    return 0;
}
