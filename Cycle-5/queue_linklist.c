//Queue using Linked List
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *rear = NULL;                                 
struct Node *front = NULL;

void enqueue(int value)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));    
  	temp->data = value;
  	if (front == NULL){
  		front = temp;
  		rear = temp;
  		front->next = NULL;
  		rear->next = NULL;
  	}
	  else{
	     rear->next = temp;
	     rear = temp;
	     rear->next = NULL;
	  }
}  

void dequeue()
{
    if(front == NULL){
       printf("\nStack is Empty!!!\n");
       return;
    }
    else{
       struct Node *temp = front;;
       printf("\nDeleted element: %d", temp->data);
       front = front->next;
       free(temp);
    }
}

void display()
{
    if(front == NULL)
       printf("\nQueue is Empty!!!\n");
    else{
    	struct Node *temp = front;
      while(temp->next != NULL){
	       printf("%d--->",temp->data);
	       temp = temp -> next;
       }
       printf("%d--->NULL",temp->data);
  }
}

void main()
{
    int choice, value;
    printf("\n:: Stack using Linked List ::\n");
    while(1){
       printf("\n------- MENU -------\n");
       printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
       printf("--------------------\n");
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch(choice){
	    	case 1: printf("Enter the value to be insert: ");
		    			scanf("%d", &value);
		    			enqueue(value);
		    			break;
	    	case 2: dequeue(); 
	    				break;
	    	case 3: display(); 
	    				break;
	    	case 4: exit(0);
	    	default: printf("\nInvalid Option\n");
        }
    }
}