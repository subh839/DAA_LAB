#include <stdio.h>
#include <stdlib.h>

int array[100];
int min, max;

// Min Max using divide and conquer
void min_max(int low, int high)
{
    if (low == high)
    {
        min = max = array[low];
    }
    else
    {
        if( low == high - 1)
        {
            min = array[low] < array[high] ? array[low] : array[high];
            max = array[low] > array[high] ? array[low] : array[high];
        }
        else
        {
            int mid = (low + high) / 2;
            min_max(low, mid);
            int max1 = max;
            int min1 = min;
            min_max(mid + 1, high);
            min = min1 < min ? min1 : min;
            max = max1 > max ? max1 : max;
        }
    }
}

// Main function
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    min_max(0, n - 1);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    return 0;
}