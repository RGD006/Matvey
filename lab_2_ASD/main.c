#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANGE 255

void printArray(int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copyArray(int *arr_source, int *arr_destination, int n)
{
    for (size_t i = 0; i < n; i++)
        arr_source[i] = arr_destination[i]; 
}

void insertionSort(int *arr, int n)
{
    int i, key, j;
    int* arr_copy = (int*)malloc(sizeof(int) * n);
    copyArray(arr_copy, arr, n);

    for (i = 1; i < n; i++)
    {
        key = arr_copy[i];
        j = i - 1;

        /* Перемещаем элементы arr[0..i-1], которые больше key, на одну позицию вперед */
        while (j >= 0 && arr_copy[j] > key)
        {
            arr_copy[j + 1] = arr_copy[j];
            j--;
        }
        arr_copy[j + 1] = key;
    }

    printArray(arr_copy, n);
}

void shellSort(int *arr, int n)
{
    int* arr_copy = (int*)malloc(sizeof(int) * n);
    copyArray(arr_copy, arr, n);

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr_copy[i];
            int j;
            for (j = i; j >= gap && arr_copy[j - gap] > temp; j -= gap)
                arr_copy[j] = arr_copy[j - gap];
            arr_copy[j] = temp;
        }
    }

    printArray(arr_copy, n);
}

void countSort(int *arr, int n)
{
    int output[n];
    int count[RANGE + 1], i;

    int arr_copy[n];
    copyArray(arr_copy, arr, n);

    for (i = 0; i <= RANGE; ++i)
        count[i] = 0;

    for (i = 0; i < n; ++i)
        ++count[arr_copy[i]];

    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; --i)
    {
        output[count[arr_copy[i]] - 1] = arr_copy[i];
        --count[arr_copy[i]];
    }

    for (i = 0; i < n; ++i)
        arr_copy[i] = output[i];

    printArray(arr_copy, n);
}

void insertArray(int *arr, size_t n)
{
    printf("write numbers for array: \n");
    for (size_t i = 0; i < n; i++)
    {
        printf("[%d] -> ", i);
        scanf("%d", &arr[i]);
    }
}

#define SIZE_ARRAY 5

int main()
{
    int arr[SIZE_ARRAY];

    insertArray(arr, SIZE_ARRAY);
    printf("array: ");
    printArray(arr, SIZE_ARRAY);

    int flag_end_loop = 0;

    while (!flag_end_loop)
    {
        printf("Choose the type of sorting:\n1. Insertion sort\n2. Shell sort\n3. Count sort\n");
        char choose;

        scanf("%s", &choose);
        
        switch (choose)
        {
        case '1':
            insertionSort(arr, SIZE_ARRAY);
            flag_end_loop = 1;
            break;
        case '2':
            shellSort(arr, SIZE_ARRAY);
            flag_end_loop = 1;
            break;
        case '3':
            countSort(arr, SIZE_ARRAY);
            flag_end_loop = 1;
            break;

        default:
            printf("Error with recognition of choice. Chose from 1 to 3\n");
            break;
        }
    }

    return 0;
}
