#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void* append(double* ptr_data, int* ptr_length, int* ptr_capacity, double value)
{
    if(*ptr_length > *ptr_capacity)
    {
        *ptr_capacity = *ptr_capacity * 2;
        double* ptr_list = calloc(sizeof(double) * *ptr_capacity, sizeof(double));
        if(ptr_list == NULL)
            return ptr_data;
        for(int i = 0;i < *ptr_length; ++i)
            ptr_list[i] = ptr_data[i];
        
        free(ptr_data);
        ptr_data = ptr_list;
    }
    ptr_data[*ptr_length] = value;
    (*ptr_length)++;
    
    return ptr_data;
}

int main(void)
{
    int capacity = 5;
    int length = 0;
    double* ptr_data = calloc(sizeof(double) * capacity, sizeof(double));
    for(int i = 0; i < 13; ++i)
    {
        ptr_data = append(ptr_data, &length, &capacity, (double)i);
    }
    for(double* i = ptr_data; i < &ptr_data[capacity]; ++i)
    {
        printf("%lg\n", *i);
    }
    printf("%d", capacity);
    return 0;
}