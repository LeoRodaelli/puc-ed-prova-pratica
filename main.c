#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Lista/Lista.h"
#include "Pilha/Pilha.h"

int getBase(int base) {
    int value = 0;

    value = sqrt(base * 2 + 1);

    return value;
}

int main(){
    struct nodeLista *root = NULL;
    // Calculo
    int insert = 0;

    printf("Digite a quantidade de copos:");
    scanf("%d", &insert);

    int base = getBase(insert);

    int inicioAlfabeto = 97;

    for(int i = base-1; i >= 0; i--){

        insertLista(&root, insert);
        inicioAlfabeto = insertPilha(root, inicioAlfabeto, i, insert);

    }
    printLista(root);
    return 0;
}