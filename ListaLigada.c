//
// Created by leoro on 01/12/2022.
//

#include "ListaLigada.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao para inicializacao a lista
void initLista(ListaLigada *lista) {
    lista->primeiro=NULL;
    lista->ultimo=NULL;
}
// Funcao para inserir no comeco da lista
int inserirComeco(ListaLigada *lista, void *valor) {
    int retorno=1;
    No *tmp = (No *) malloc(sizeof(No));
    if (tmp!=NULL) { // Conseguiu alocar?
        tmp->dado=valor;
        tmp->prox=lista->primeiro;
        lista->primeiro=tmp; // Temos um novo primeiro
        if (lista->ultimo==NULL) // Se nao tinha ninguem, o ultimo tambem eh o novo elemento
            lista->ultimo=tmp;
    }
    else {
        retorno=0;
    }
    return retorno;
}
// Funcao para remocao do comeco da lista
void * removerComeco(ListaLigada *lista) {
    No *tmp=lista->primeiro;
    void *dado;
    if (lista->primeiro==NULL) // Nao existe elemento a remover
        dado=NULL;
    else {
        if (lista->primeiro==lista->ultimo) // So tem um elemento
            lista->ultimo=NULL; // Nao tem mais ultimo, lista vazia
        lista->primeiro=lista->primeiro->prox; // O novo primeiro eh o proximo do primeiro anterior
        // Sera retirado o no da lista, entao retorna o dado que estava la
        dado=tmp->dado;
        /*
          tmp->dado=NULL;
          tmp->prox=NULL;
        */
        free(tmp); // Libera a memoria do no
    }
    return dado;
}
// Libera toda a memoria utilizada pela lista (se ainda tiver elementos)
void deleteLista(ListaLigada *lista) {
    // Liberando a memoria de todos os elementos alocados/colocados na lista(elemento a elemento) ate zerar a lista
    while (lista->primeiro != NULL) {
        printf("Liberando os elementos ainda na lista: [val=%p, primeiro=%p, ultimo=%p]\n", lista->primeiro->dado,
               lista->primeiro, lista->ultimo);
        No *tmp = lista->primeiro->prox;
        free(lista->primeiro->dado); // Libera o ponteiro do dado
        free(lista->primeiro); // Libera o primeiro no
        lista->primeiro = tmp; // Avanca o primeiro para o proximo da lista
    }
    lista->ultimo = NULL; // Se nao existe mais ninguem o ultimo tambem nao existe
}