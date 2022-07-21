#include <stdio.h>
#include <stdlib.h>

// Binary search function
int binary_search(int *array, int size, int value)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == value)
        {
            return mid;
        }
        else if (array[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// Main function
int main()
{
    int size, value, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(sizeof(int) * size);
    printf("Enter the values of the array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the value to be searched: ");
    scanf("%d", &value);
    int index = binary_search(array, size, value);
    if (index == -1)
    {
        printf("Value not found in the array.\n");
    }
    else
    {
        printf("Value found at index %d.\n", index);
    }
    return 0;
}