#include <stdio.h>
#include <math.h>

//Defining Structure Polynomial
struct poly{
    int coeff;
    int expo;
}p1[10];

int main(){
    int terms,i,x;
    int sum = 0;
    //Reading a Polynomial
    printf("Enter the no. of terms: ");
    scanf("%d",&terms);
    printf("Enter the Coefficient and Exponents in the DESCENDING ORDER: \n");
    for(i=0;i<terms;i++)
    {
        //Entering the coefficients
        printf("Enter the coefficient of the polynomial:");
        scanf("%d",&p1[i].coeff);
        //Entering the exponents 
        printf("Enter the exponents of the polynomial:");
        scanf("%d",&p1[i].expo);
    }
    //Entering the value of x
    printf("Enter the value of x: ");
    scanf("%d",&x);

    //Substituting the value of x in the polynomial
    for(i=0;i<=terms;i++)
    {
        sum = sum + p1[i].coeff * pow(x,p1[i].expo);
    }
    printf("Sum = %d",sum);
}

