#include <stdio.h>
#include <stdlib.h>

// Linear search function
int linear_search(int *array, int size, int value)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return i;
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
    int index = linear_search(array, size, value);
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