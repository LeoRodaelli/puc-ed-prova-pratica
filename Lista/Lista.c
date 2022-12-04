# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#include "Lista.h"
#include "../Pilha/Pilha.h"

int coposInseridos = 0;

void insertLista(struct nodeLista **root, int totalCopos){
    if(coposInseridos == totalCopos){
        return;
    }

    struct nodeLista *temp;
    temp = (struct nodeLista*)malloc(sizeof(struct nodeLista));
    temp->data = NULL;
    temp->next = NULL;

    if(*root == NULL){
        *root = temp;
        return;
    }

    struct nodeLista *searcher = *root;

    while(searcher->next != NULL){
        searcher = searcher->next;
    }

    searcher->next = temp;
}

void printLista(struct nodeLista *searcher){

    struct nodePilha *searcherPilha = NULL;

    while(searcher != NULL){
        printf("%d ", searcher->data);

        searcherPilha = searcher->data;

        while(searcherPilha != NULL){

            printf("%c ", searcherPilha->data);
            searcherPilha = searcherPilha->next;

        }

        printf("\n");
        searcher = searcher->next;
    }
}

