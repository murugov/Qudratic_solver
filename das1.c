#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void* append(double* ptr_data, int* ptr_length, int* ptr_capacity)
{
    if(*ptr_length >= *ptr_capacity)
    {
        *ptr_capacity = *ptr_capacity * 2;
        double* ptr_list = (double *)calloc(*ptr_capacity, sizeof(double));
        if(ptr_list == NULL)
            return ptr_data;

        for(int i = 0;i < *ptr_length; ++i)
            ptr_list[i] = ptr_data[i];
        
        free(ptr_data);
        ptr_data = ptr_list;
    }
    
    return ptr_data;
}

int main(void)
{
    int capacity = 5;
    int length = 0;
    double* ptr_data = (double *)calloc(capacity, sizeof(double));
    if (!ptr_data) {
        perror("> error while allocating memory\n");
        return 1;
    }

    FILE* ptr_file = fopen("test_input.txt", "r");
    if(ptr_file == NULL) {
        perror("test_input.txt");
        return 1;
    }

    char nan_proof[5];

    while(1)
    {
        if(fscanf(ptr_file, "%lg, ", ptr_data + length) == 1)
        {
            ptr_data = append(ptr_data, &length, &capacity);
            length++;
            printf("999\n");
            continue;
        }
        // else if(fscanf(ptr_file, "%s ", nan_proof) == 1 && !strcmp(nan_proof, "NAN"))
        // {
        //     printf("777\n");
        //     ptr_data[length] = NAN;
        //     ptr_data = append(ptr_data, &length, &capacity);
        //     length++;
        //     continue;
        //        }
        else
        {
            break;
        }
    }

    for(int i = 0; i < length; ++i)
        printf("%lg ", ptr_data[i]);
 
    fclose(ptr_file);
 
    return 0;
}


