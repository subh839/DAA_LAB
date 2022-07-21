#include <stdio.h>
#include <stdlib.h>

// Partition function
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

// Quick sort function
void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

// Main function
int main()
{
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(sizeof(int) * size);
    printf("Enter the values of the array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    quick_sort(array, 0, size - 1);
    printf("Sorted array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

