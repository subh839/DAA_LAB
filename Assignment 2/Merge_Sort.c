#include <stdio.h>
#include <stdlib.h>

// Merge function
void merge(int* arr, int mid, int low, int high){
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++){
        L[i] = arr[low + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = low;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void merge_sort(int* arr, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}

// Main function
int main(){
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(sizeof(int) * size);
    printf("Enter the values of the array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    merge_sort(array, 0, size - 1);
    printf("Sorted array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
