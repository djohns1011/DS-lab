#include <stdio.h>

void main(){
    int array[10];
    int x;
    int low = 0;
    int high = 10;
    int mid;
    int flag = 0;
    printf("Enter 10 elements:");
    for(int i = 0; i<10; i++){
        scanf("%d",&array[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    while(low < high){
        mid = (low+high)/2;
        if (array[mid] == x){
            printf("Element found at position %d",mid+1);
            flag = 1;
            break;
        }
        else if (array[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if (flag == 0){
        printf("Element not found");
    }
}