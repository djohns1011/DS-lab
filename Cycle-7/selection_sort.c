#include <stdio.h>

void main(){
    int array[10];
    int n;
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
    for(int i = 0; i < n; i++){
        printf("%d ",array[i]);
    }
    printf("]\n");
    //Performing selection sort
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
    //Displaying the array after Selection Sort
    printf("Elements in array after Selection Sort\n");
    printf("[");
    for(int i = 0; i < n; i++){
        printf("%d ",array[i]);
    }
    printf("]\n");
}