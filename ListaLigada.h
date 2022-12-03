//
// Created by leoro on 01/12/2022.
//

#ifndef ED_PROVA_PRATICA_LISTALIGADA_H
#define ED_PROVA_PRATICA_LISTALIGADA_H

// Facilitando a criacao de elementos que irao para a lista
#define novo_elemento(tipo) \
  (tipo *) malloc(sizeof(tipo))
// Minha estrutura generica de no da lista
typedef struct no {
    void *dado;
    struct no *prox;
} No;
// Minha estrutura de lista (com todos os ponteiros importantes dela)
typedef struct {
    No *primeiro;
    No *ultimo;
} ListaLigada;
void initLista(ListaLigada *lista);
int inserirComeco(ListaLigada *lista, void *valor);
void * removerComeco(ListaLigada *lista);
void deleteLista(ListaLigada *lista);
#else
#warning O arquivo ja foi incluido anteriormente.

#endif //ED_PROVA_PRATICA_LISTALIGADA_H
