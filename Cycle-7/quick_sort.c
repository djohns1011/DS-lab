#include <stdio.h>

int array[10];
int temp[10];
int n;
int mid;

void swap(int array[], int left, int right){
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}

int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if (array[j] < pivot){
            i++;
            swap(array,i,j);
        }
    }
    swap(array,i+1,high);
    return (i+1);
}

void quick_sort(int array[], int low, int high){
    if(high > low){
        int pivot = partition(array,low,high);
        quick_sort(array,low,pivot-1);
        quick_sort(array,pivot+1,high);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", A[i]);
}

void main(){
    //Entering the elements in an array
    printf("Enter the no. of elements (n<10):");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&array[i]);
    }
    //Displaying the elements of an array
    printf("Elements in an array:\n");
    printf("[");
    printArray(array, n);
    printf("]\n");
    //Performing quick sort
    quick_sort(array,0,n-1);
     //Displaying the array after Quick Sort
    printf("Elements in array after Quick Sort\n");
    printf("[");
    printArray(array, n);
    printf("]\n");
}