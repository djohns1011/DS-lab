//Convert a given decimal number into binary and hex
#include <stdio.h>
#define MAX 100
int stack[MAX],top=-1;

//Add an element
void push(int data)
{
    if(top==MAX-1)
        printf("\nStack Overflow.");
    else
        stack[++top]=data;    
}

//Delete an element
int pop()
{
    int del;
    if(top==-1)
    {
        printf("\nStack empty.");
        return -1;
    }
    else
    {
        del=stack[top--];
        return del;
    }
}

//Decimal to Binary Conversion
void ToBinary(int num)
{
    while(num)
    {
        push(num%2);
        num/=2;
    }
}

//Display Binary no.
void displayBinary()
{
    printf("\nBinary : ");
    while(top!=-1)
    {
        printf("%d",pop());
    }
    printf("\n");
}

//Decimal to Hexa-decimal Conversion
void ToHex(int num)
{
    while(num)
    {
        push(num%16);
        num/=16;
    }
}

//Display Hexa-decimal no.
void displayHex()
{
    printf("\nHex : ");
    while(top!=-1)
    {
        int disp = pop();
        switch(disp)
        {
            case 10:
                printf("A");
                break;

            case 11:
                printf("B");
                break;

            case 12:
                printf("C");
                break;

            case 13:
                printf("D");
                break;

            case 14:
                printf("E");
                break;

            case 15:
                printf("F");
                break;

            default:
                printf("%d",disp);
                break;            
        }
    }
    printf("\n\n");
}

//Main function
int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d",&num);
    ToBinary(num);
    displayBinary();
    ToHex(num);
    displayHex();
    return 0;
}

