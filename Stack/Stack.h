#ifndef ED_PROVA_PRATICA_STACK_H
#define ED_PROVA_PRATICA_STACK_H

//Creating a node structure
struct node {
    char c;
    struct node *link;
};

//Creating a stack structure
struct stack {
    struct node *top;
};

void push(struct stack *s, char data);
char pop(struct stack *s);
int getBase(int base);

#endif //ED_PROVA_PRATICA_STACK_H
