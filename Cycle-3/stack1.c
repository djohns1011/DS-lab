#include<stdio.h>
#include<stdlib.h>
 
#define Size 5
 
int Top=-1, inp_array[Size];
void Push();
void Pop();
void Peek();
void Display();
 
//Main Function
int main()
{
	int choice;
	
	while(1)	
	{
		printf("\nOperations performed by Stack");
		printf("\n1.Push the element\n2.Pop the element\n3.Peek\n4.Display\n5.End");
		printf("\n\nEnter the choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: Push();
					break;
			case 2: Pop();
					break;
			case 3: Peek();
					break;
			case 4: Display();
					break;
			case 5: exit(0);
			
			default: printf("\nInvalid choice!!");
		}
	}
}
 
//Add an element
void Push()
{
	int x;
	
	if(Top==Size-1)
	{
		printf("\nOverflow!!");
	}
	else
	{
		printf("\nEnter element to be inserted to the stack:");
		scanf("%d",&x);
		Top=Top+1;
		inp_array[Top]=x;
	}
}
 
//Delete an element
void Pop()
{
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nPopped element:  %d",inp_array[Top]);
		Top=Top-1;
	}
}

//Displaying the top of the stack
void Peek()
{
	printf("Peek : %d",inp_array[Top]);
}

//Displaying the elements of a stack
void Display()
{
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nElements present in the stack: \n");
		for(int i=Top;i>=0;--i)
			printf("%d\n",inp_array[i]);
	}
}