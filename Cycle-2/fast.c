#include <stdio.h>

typedef struct {
    int row;
    int col;
    int val;
}matrix;

void readtoSparse(matrix a[],int count){
    int m,n,spar,element,k=1;
    float sparsity;
    printf("Enter no. of rows of matrix %d: ",count);
    scanf("%d",&m);
    printf("Enter no. of columns of matrix %d:",count);
    scanf("%d",&n);
    a[0].row = m;
    a[0].col = n;
    printf("Enter elements of matrix: \n");
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&element);
            if(element != 0){
                spar++;
                a[k].row = i;
                a[k].col = j;
                a[k].val = element;
                k++;
            }
        }
    }
    a[0].val = k-1;
}

void fast_transpose(matrix a[], matrix b[]){
    int row_terms[a[0].col];
    int starting_pos[a[0].col];

    int num_cols = a[0].col, num_terms = a[0].row;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    if (a[0].val > 0){
        for(int i = 0 ; i < num_cols; i++){
            row_terms[i] = 0;
        }
        for(int i = 0; i <= *row_terms; i++){
            row_terms[a[i].col]++;
            starting_pos[0] = 1;
        }
        for(int i = 0; i < num_cols; i++){
            starting_pos[i] = starting_pos[i-1] + starting_pos[i-1];
        }
        for(int i = 0; i <= num_terms; i++){
            int j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
    }
}

void display(matrix b[]){
    printf("Rows\tColumns\tValue");
    for(int i = 0; i < b[i].col; i++){
        printf("%d\t%d\t%d", b[i].row,b[i].col,b[i].val);
    }
}

void main(){
    matrix a[100],b[100];
    readtoSparse(a,1);
    fast_transpose(a,b);
    printf("\n\nEntered Matrix: ");
    display(a);
    printf("\n\nTranspose Matrix: ");
    display(b);
}