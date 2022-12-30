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
    //Performing bubble sort
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    //Displaying the array after Bubble Sort
    printf("Elements in array after Bubble Sort\n");
    printf("[");
    for(int i = 0; i < n; i++){
        printf("%d ",array[i]);
    }
    printf("]\n");
}