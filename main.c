#include<stdio.h>
#include<stdlib.h>
#include "Stack/Stack.h"
#include "math.h"

int main()
{
    int num;
    char i;

    printf("Enter the number of cups:");
    scanf("%d", &num);

    if(num <= 0 || num > 26) {
        printf("Numero de copos invalido!");
    }
    else {
        printf("Total de copos: %i \n", num);
        printf("total fileiras: %d \n", getBase(num));

        printf("Total de copos por fileira: ");
        for(int index = getBase(num); index >= 1; index--) {
            if(index != 1)
                printf("%i, ", index);
            else
                printf("%i", index);
            }
        printf("\n");

        //Creating the stack
        struct stack s;
        s.top = NULL;

        //Pushing alphabets into the stack
        for(i='A'; i<='@'+num; i++) {
            push(&s, i);
        }

        //Printing the cup tower
        for(i=0; i<num; i++) {
            //Creating a temporary stack to store the characters in the current row
            struct stack temp;
            temp.top = NULL;

            for(int j=i; j<num; j++) {
                printf(" ");
            }

            for(int k=0; k<=i; k++) {
                //Pushing the character from the current row into the temporary stack
                push(&temp, pop(&s));
            }

            //Popping the characters from the temporary stack in reverse order to invert the row
            for(int l= i; l>=0; l--) {
                printf("%c ", pop(&temp));
            }

            printf("\n");
        }
    }
    return 0;
}

