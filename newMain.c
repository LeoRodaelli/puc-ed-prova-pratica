#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int coposInseridos = 0;

struct nodeLista{
    struct nodePilha *data;
    struct nodeLista *next;
};

struct nodePilha{
    char data;
    struct nodePilha *next;
};

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

int insertPilha(struct nodeLista *searcherLista, int startLetra, int qtdLetra, int totalCopos){
    int i = startLetra;
    while(searcherLista->next != NULL){
        searcherLista = searcherLista->next;
    }

    for(i = startLetra; i <= (startLetra+qtdLetra); i++) {

        if(coposInseridos == totalCopos){
            printf(" parou ");
            return i;
        }

        struct nodePilha *temp = (struct nodePilha*)malloc(sizeof(struct nodePilha));
        temp->data = (char)i;
        temp->next = NULL;
        coposInseridos++;

        if (searcherLista->data == NULL){
            searcherLista->data = temp;
        } else {
           temp->next = searcherLista->data;
           searcherLista->data = temp;
        }

    }

    return i;

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

int getBase(int base) {
  int value = 0;

  value = sqrt(base * 2 + 1);

  return value;
}

void main(){
    struct nodeLista *root = NULL;
    // Calculo
    int insert = 0;

    printf("Digite a quantidade de copos: ");
    scanf("%d", &insert);

    int base = getBase(insert);

    int inicioAlfabeto = 97;

    for(int i = base-1; i >= 0; i--){

        insertLista(&root, insert);
        inicioAlfabeto = insertPilha(root, inicioAlfabeto, i, insert);

    }
    printLista(root);
    return;
}
