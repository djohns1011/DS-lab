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
    //Performing insertion sort
    int i = 1;
    while(i<n){
        int v = array[i];
        int j = i;
        while(array[j-1]>v && j>0){
            array[j] = array[j-1];
            j = j-1;
        }
        array[j] = v;
        i = i + 1;
    }
    //Displaying the array after Insertion Sort
    printf("Elements in array after Insertion Sort\n");
    printf("[");
    for(int i = 0; i < n; i++){
        printf("%d ",array[i]);
    }
    printf("]\n");
}