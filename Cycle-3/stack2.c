//Implement multiple stacks using an array
#include<stdio.h>
#include<stdlib.h>

#define Size 4
int Top1=-1,Top2 = Size, stack[Size]; 
void Push1(); 
void Push2(); 
void Pop1(); 
void Pop2(); 
void Display(); 

//Main Function
int main() {
	int choice; 
	while(1) { 
		printf("\nOperations performed by Stack"); 
		printf("\n1.Push stack1\n2.Push stack2\n3.Pop stack1\n4.Pop stack2\n5.Display \n6.Exit"); 
		printf("\n\nEnter the choice:"); 
		scanf("%d",&choice); 
		switch(choice) { 
			case 1: Push1(); 
						  break; 
	    case 2: Push2(); 
	    			  break; 
	    case 3: Pop1(); 
	    				break; 
	    case 4: Pop2(); 
	    				break; 
	    case 5: Display(); 
	    				break; 
	 		case 6: exit(0); 
	 		default: printf("\nInvalid choice!!");
	 	} 
	} 
} 

//Adding elements to stack1
void Push1() { 
	int x;
	if(Top1==Top2) { 
		printf("\nStack is Full");
  } 
  else { 
  	printf("\nEnter element to be inserted to the stack:"); 
  	scanf("%d",&x); Top1=Top1+1; 
  	stack[Top1]=x; 
  } 
} 

//Adding elements to stack2
void Push2() {
	int x; 
	if(Top2==Top1) {
		printf("\nStack is Full");
	} 
	else { 
		printf("\nEnter element to be inserted to the stack:"); 
		scanf("%d",&x); 
		Top2=Top2-1; 
		stack[Top2]=x; 
	} 
} 

//Deleting an element from stack1
void Pop1() {
	if(Top1==-1) { 
		printf("\nStack is Empty!!"); 
	} 
	else { 
		printf("\nPopped element: %d",stack[Top1]); 
		Top1=Top1-1;
	} 
} 

//Deleting an element from stack2
void Pop2() {
	if(Top2==-1) { 
		printf("\nStack is Empty!!");
	}
	else { 
		printf("\nPopped element: %d",stack[Top2]);
		Top2=Top2+1;
	}
}

//Displaying the elements from both stacks
void Display() {
	if(Top1==-1) {
		printf("\nStack 1 is Empty!!");
	} 
	else { 
		printf("\nElements present in the stack 1 : \n"); 
		for(int i=Top1;i>=0;--i) 
			printf("%d\n",stack[i]);
	} 
	if(Top2==Size) { 
		printf("\nStack 2 is Empty!!");
	} 
	else { 
		printf("\nElements present in the stack 2: \n");
		for(int i=Top2;i<Size;i++)
		printf("%d\n",stack[i]); 
	} 
}