//Double Ended Queue using Double Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront(int value){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if (front == NULL){
        front = temp;
        rear = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else{
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}

void insertRear(int value){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if (rear == NULL){
        front = temp;
        rear = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }   
    else{
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
        temp->next = NULL;
    }
}

void deleteFront(){
    if (front == NULL){
        printf("Queue Underflow");
    }
    else{
        struct Node *temp = front;
        printf("Deleted element: %d", temp->data);
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }
        else{
            front->prev = NULL;
        }
        free(temp);
    }
}

void deleteRear(){
    if (rear == NULL){
        printf("Queue Underflow");
    }
    else{
        struct Node *temp = rear;
        printf("Deleted element: %d",temp->data);
        rear = rear->prev;
        if (rear == NULL){
            front = NULL;
        }
        else{
            rear->next = NULL;
        }
        free(temp);
    }
}

void display(){
    if (front == NULL){
        printf("Queue is Empty");
    }
    else{
        struct Node *temp = front;
        printf("NULL <=> ");
        while(temp->next != NULL){
            printf("%d <=> ", temp->data);
            temp = temp->next;
        }
        printf("%d <=> NULL", temp->data);
    }
}

void main()
{
    int choice, value;
    printf("\n:: Double Ended Queue using Linked List ::\n");
    while(1){
       printf("\n------- MENU -------\n");
       printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
       printf("--------------------\n");
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch(choice){
	    	case 1: printf("Enter the value to be insert at front: ");
		    		scanf("%d", &value);
		    		insertFront(value);
		    		break;
	    	case 2: printf("Enter the value to be insert at rear: ");
		    		scanf("%d", &value);
		    		insertRear(value); 
	    			break;
            case 3: deleteFront();
                    break;
            case 4: deleteRear();
                    break;
	    	case 5: display(); 
	    			break;
	    	case 6: exit(0);
	    	default: printf("\nInvalid Option\n");
        }
    }
}
