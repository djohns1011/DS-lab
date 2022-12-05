//Check whether a string is palindrome 

#include <malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* stack;
int top = -1;

//add element 
void push(char ele)
{
    stack[++top] = ele;
}

//delete element
 char pop()
{
    return stack[top--];
}

//Palindrome Function
int isPalindrome(char str[])
{
    int length = strlen(str);
    //Allocating size for stack
    stack = (char*)malloc(length * sizeof(char));
    int i, mid = length / 2;
    for (i = 0; i < mid; i++) {
        push(str[i]);
    }
    if (length % 2 != 0) {
        i++;
    }
    while (str[i] != '\0') {
       char ele = pop();
       if(tolower(ele) != tolower(str[i]))
       //  if (ele != str[i])
           return 0;
       i++;
    }
    return 1;
}

//Main Function
int main()
{
    char str[50];
    printf("Enter a string : ");
    scanf("%s",str);
    if (isPalindrome(str)) {
        printf("Palindrome\n");
    }
    else {
        printf("Not Palindrome\n");
    }
     return 0;
}