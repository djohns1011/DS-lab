#include <stdio.h>

void main(){
    int array[10];
    int x;
    int n;
    int flag = 0;
    printf("Enter 10 elements:");
    for(int i = 0; i<10; i++){
        scanf("%d",&array[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    for(int i = 0; i<10; i++){
        if (array[i] == x){
            printf("Element found at position %d",i+1);
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("Element not found");
    }
}