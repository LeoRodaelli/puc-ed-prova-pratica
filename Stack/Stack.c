# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#include "Stack.h"
#include "math.h"

//Function to push character into stack
void push(struct stack *s, char data) {
    //Allocating memory for the node
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->c = data;
    temp->link = s->top;
    s->top = temp;
}

//Function to pop character from stack
char pop(struct stack *s) {
    struct node *temp;
    char data;
    temp = s->top;
    data = temp->c;
    s->top = temp->link;
    free(temp);
    return data;
}

int getBase(int base) {
    int value = 0;

    value = sqrt(base * 2 + 1);

    return value;
}


