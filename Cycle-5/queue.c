//Queue using array
#include <stdio.h>
#include <stdlib.h>
#define size 10

int queue[size];
int rear = -1;
int front = -1;

void enqueue(int data){
	if (rear == size-1){
		printf("Queue Overflow\n");
	}
	else if (rear == -1){
		front = rear = 0;
		queue[rear] = data;
	}
	else{
		queue[++rear] = data;
	}
}

void dequeue(){
	if (front == -1){
		printf("Queue Underflow\n");
	}
	else if (front == rear){
		printf("Deleted Element: %d\n",queue[front]);
		front = rear = -1;
	}
	else{
		printf("Deleted Elemet: %d\n",queue[front++]);
	}
}

void peek(){
	if (front == -1){
		printf("Queue is Empty\n");
	}
	else{
		printf("Element at rear: %d\n",queue[rear]);
	}
}

void display(){
	if (front == -1){
		printf("Queue is Empty\n");
	}
	else{
		for(int i = front; i<=rear; i++){
			printf("%d ",queue[i]);
		}
	}
}

int main(){
	int choice;
	int value;
	while(1){
		printf("\n----------------Menu----------------\n");
		printf("1.Enqueue \n2.Dequeue \n3.Peek \n4.Display \n5.Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
			switch(choice){
				case 1: printf("Enter a value: ");
								scanf("%d",&value);
								enqueue(value);
								break;
				case 2: dequeue();
								break;
				case 3: peek();
								break;
				case 4: display();
								break;
				case 5: exit(0);
				default: break;
		}
	}
}
						
	






