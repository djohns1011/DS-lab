#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *stack;
int tos=-1,tos2,m,n;;

void push(char item){
	if(tos == n-1){
		printf("Stack Overflow");
		exit(0);	
	}
	else{
	 	stack[++tos]=item;
	}
}


char pop(){
	if(tos < 0){
		printf("Stack Underflow");
		exit(0);
	}
	else{
	 	return stack[tos--];
	}
}

void checkPalindrome(char str[]){
	int i=0;
	while(i < n/2){
		push(str[i]);
		i++;
	}
	if(n%2 != 0){
		i++;
	}
	while(i< n){
		if(pop() != str[i]){
			printf("Not Palindrome");
			return;
		}
		i++;
	}
	printf("Palindrome");
}

void main(){
	char str[100];
	printf("Enter the String: ");
	gets(str);
	n = strlen(str);
	stack = (char*) calloc(n,sizeof(char));
	checkPalindrome(str); 
}
