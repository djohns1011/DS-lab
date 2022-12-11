//Polynomial Addition using Double Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node *next;
};

void createPolynomial(struct Node *head, int coeff, int exp){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL){
        temp->coeff = coeff;
        temp->exp = exp;
        temp->next = NULL;
        head = temp;
    }
    else{
        while (temp->next != NULL){
            temp = temp->next;
        }
        struct Node *flag;
        flag = (struct Node*)malloc(sizeof(struct Node));
        flag->coeff = coeff;
        flag->exp = exp;
        flag->next = NULL;
        temp->next = flag;
    }
}

void addPolynomials(struct Node *p1, struct Node *p2, struct Node *sum){
    struct Node *poly1 = p1;
    struct Node *poly2 = p2;
    struct Node *res;
    int sum;

    //If polynomial 2 is null, set polynomial 1 as the sum
    if ((poly1 != NULL) && (poly2 == NULL)){
        sum = poly1;
        return sum;
    }
    //If polynomial 1 is null, set polynomial 2 as the sum
    else if((poly1 == NULL) && (poly2 != NULL)){
        sum = poly2;
        return sum;
    }
    //If both polynomials are not null
    else if((poly1 != NULL) && (poly2 != NULL)){
        sum = (struct Node*)malloc(sizeof(struct Node));

        if(poly1->exp > poly2->exp){
            sum->coeff = poly1->coeff;
            sum->exp = poly1->exp;
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp){
            sum->coeff = poly2->coeff;
            sum->exp = poly2->exp;
            poly2 = poly2->next;
        }
        else if(poly1->exp == poly2->exp){
            sum->coeff = poly1->coeff + poly2->coeff;
            sum->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        while(poly1 != NULL){
            sum->coeff = poly1->coeff;
            sum->exp = poly1->exp;
            poly1 = poly1->next;
        }
        while(poly2 != NULL){
            sum->coeff = poly2->coeff;
            sum->exp = poly2->exp;
            poly2 = poly2->next;
        }
    }
}
