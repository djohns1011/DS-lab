//Convert a given infix expression to postfix/prefix
#include<stdio.h>
#include<stdlib.h>      
#include<ctype.h>     
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

//add element
void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

//delete an element
char pop()
{
	char item ;
	
	if(top < 0)
	{
		printf("stack under flow: invalid infix expression");
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

//Checking for operator
int operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Precedence of operators
int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

//Converting Inflix to Postflix
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               
	strcat(infix_exp,")");                 
	i=0;
	j=0;
	item=infix_exp[i];         

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              
			j++;
		}
		else if(operator(item) == 1)      
		{
			x=pop();
			while(operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  
				j++;
				x = pop();                       
			}
			push(x);
			push(item);                 
		}
		else if(item == ')')         
		{
			x = pop();                  
			while(x != '(')                
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");       
			exit(1);
		}
		i++;
		item = infix_exp[i]; 
	} 
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n"); 
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0';
}

//Main Function
int main()
{
	char infix[SIZE], postfix[SIZE];         
	//The infix expression contains single letter variables and single digit
	printf("\nEnter Infix expression : ");
	gets(infix);

	InfixToPostfix(infix,postfix);                  
	printf("Postfix Expression: ");
	puts(postfix);                     

	return 0;
}
