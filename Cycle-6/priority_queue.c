#include <stdio.h>
#include <stdlib.h>
#define MAX 6

int array[MAX];
int front = -1;
int rear = -1;

void peek(){
    int top = array[front];
    printf("Element at the front: %d",top);
}

void enqueue(int data){
    int i;
    if(rear == MAX){
        printf("Queue Overflow");
    }
    else{
        if(front == -1){
            front = rear = 0;
            array[rear] = data;
        }
        else{
            for(i = rear; i>=0; i--){
                if(data > array[i]){
                    array[i+1] = array[i];
                }
                else{
                    break;
                }
            }
            array[i+1] = data;
            rear++;
        }
    }
}

void dequeue(){
	if (front == -1){
		printf("Queue Underflow\n");
	}
	else if (front == rear){
		printf("Deleted Element: %d\n",array[front]);
		front = rear = -1;
	}
	else{
		printf("Deleted Elemet: %d\n",array[front++]);
	}
}

void display(){
    if (front == -1){
        printf("Queue is Empty");
    }
    else{
        for(int i = front; i <= rear; i++){
            printf("index: %d\t",i);
            printf("item: %d\t",array[i]);
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

