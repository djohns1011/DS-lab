#include <stdio.h>

int array[10];
int n;

void swap(int array[], int i, int l){
    int temp = array[i];
    array[i] = array[l];
    array[l] = temp;
}

void heapify(int array[], int n, int i ){
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largest = i;
    if (L < n && array[L] > array[largest]){
        largest = L;
    }
    if (R < n && array[R] > array[largest]){
        largest = R;
    }
    if (largest != i){
        swap(array,i,largest);
        heapify(array,n,largest);
    }
}

void buildHeap(int array[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(array,n,i);
    }
}

void heap_sort(int array[],int n){
    buildHeap(array,n);
    for(int i = n-1; i >= 0; i--){
        swap(array,i,0);
        heapify(array,i,0);
    }
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	//Entering the elements in an array
    printf("Enter the no. of elements (n<10):");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&array[i]);
    }
	printf("Given array is \n");
	printArray(array, n);

	heap_sort(array, n);

	printf("\nSorted array is \n");
	printArray(array, n);
	return 0;
}