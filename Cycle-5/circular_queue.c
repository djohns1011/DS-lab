//Circular Queue using array
#include <stdio.h>
#include <stdlib.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int value){
    if (front == -1){
        front = rear = 0;
        queue[rear] = value;
    }
    else {
        if (((rear + 1) % size) != front){
            rear = (rear + 1) % size;
            queue[rear] = value;
        }
        else{
            printf("Queue Overflow");
        }
    }
}

void dequeue(){
    if (front == -1){
        printf("Queue Underflow");
    }
    else {
        int value = queue[front];
        printf("Deleted Element: %d", value);
        if (front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
    }
}

void display(){
    int i = front;
    if (front == -1){
        printf("Queue is Empty");
    }
    else{
        while (i != rear){
            printf("%d ", queue[i]);
            i = (i+1)%size;
        }
        printf("%d ",queue[i]);
    }
}

void main()
{
    int choice, value;
    printf("\n:: Circular Queue using Array ::\n");
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