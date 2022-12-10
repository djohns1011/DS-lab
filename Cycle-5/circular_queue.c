#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if (front == NULL){
        front = temp;
    }
    else{
        rear->next = temp;    
    }
    rear = temp;
    rear->next = front;
}

void dequeue(){
    if (front == NULL){
        printf("Circular Queue Overflow\n");
        return;
    }
    else if(front == rear){
        struct Node *temp = front;
        printf("Deleted element: %d", temp->data);
        front = rear = NULL;
        free(temp);
    }
    else{
        struct Node *temp = front;
        printf("Deleted element: %d", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display(){
    if (front == NULL){
        printf("Circular Queue is Empty\n");
        return;
    }
    else{
        struct Node *temp = front;
        while(temp->next != front){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ",temp->data);
    }
}

void main()
{
    int choice, value;
    printf("\n:: Circular Queue using Linked List ::\n");
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
