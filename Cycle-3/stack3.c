//Find the minimum element in a stack in O(1) time using an auxilliary stack which keeps track of the minimum element.
#include<stdio.h> 
#include<stdlib.h> 
#define Size 10
int Top=-1, inp_array[Size]; 
int Top2=-1,aux[Size];
int flag=0;
void Push(); 
void Pop();
void Peek(); 
void Display(); 

typedef struct{
    int num;
}stack;

//Declaring Stack and Auxilary Stack.
stack s[Max_Size],aux[Max_Size]; 
int Top=-1;
int auxTop=-1;


//Function to Push
void push(int element){

    if (Top == Max_Size-1){
        printf("\nStack is Full\n");
    }
    else{
        s[++Top].num = element;
        printf("\n%d added to Stack\n",s[Top].num);

        if (auxTop == -1){
            //if the Auxilary Stack is empty then push the element into it
            //First element in aux is minimum by default.
            aux[++auxTop].num=element;
        }
        else{
            //push the element into the Auxilary Stack
            //if it is less than or equal to the current minimum.
            if (element<=aux[auxTop].num){
                aux[++auxTop].num=element;
            }   
        }
    }
}
 
void Push() { 
	int x; 
	if(Top==Size-1) { 
		printf("\nStack is Full"); 
	} 
	else { 
		printf("\nEnter element to be inserted to the stack:"); 
		scanf("%d",&x); 
		Top=Top+1; 
		inp_array[Top]=x;
		if (flag==0){
			flag=1;
			Top2++;
			aux[Top2]=x;
		}
		else if (x<aux[Top2]){

			Top2++;
			aux[Top2]=x;
		} 
	} 
}

void Pop(){
    if (Top == -1){
        printf("Stack Underflow");
    }
    else{
        int element = inp_array[Top];
        Top = Top - 1;
        if (aux[Top2] == element){
            Top2 -= 1;
        }
        printf("Deleted element: %d",element);
    }
}

//Function to Display Minimum
void min(){
    if (auxTop==-1){
        printf("\nStack is Empty\n");
    }
    else{
        printf("\nThe Minimum Element in the Stack: %d\n",aux[auxTop].num);
    }   
}


void main(){

    int option;
    //Continuous For loop
    while (1){
        int element;
        printf("    1 : Push \n");
        printf("    2 : Pop \n");
        printf("    3 : Find Minimum Element \n");
        printf("    4 : Display Stack \n");
        printf("    5 : Exit \n");
       

        printf("Enter Your Option: ");
        scanf("%d",&option);

        switch (option){
        case 1:
            printf("\nEnter Element: ");
            scanf("%d",&element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            min();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        
        default:
            printf("\n!!Enter a Valid Option!!\n");
            break;
        }
    }
}