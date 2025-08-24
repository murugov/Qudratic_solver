#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void* append(double* ptr_data, int* ptr_length, int* ptr_capacity)
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
    (*ptr_length)++;
    
    return ptr_data;
}

int main(void)
{
    int capacity = 5;
    int length = 0;
    double* ptr_data = calloc(sizeof(double) * capacity, sizeof(double));
 
    FILE* ptr_file = fopen("test_input.txt", "r");
    if(ptr_file == NULL) {
        perror("test_input.txt");
        return 1;
    }

    while(fscanf(ptr_file, "%lg ", &ptr_data[length]) == 1)
    {
        printf("%lg\n", ptr_data[length]);
        append(ptr_data, &length, &capacity);
    }

    for(int i = 0; i < length; ++i)
        printf("%lg ", ptr_data[i]);
 
    fclose(ptr_file);
 
    return 0;
}


