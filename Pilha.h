//
// Created by leoro on 01/12/2022.
//

#ifndef ED_PROVA_PRATICA_PILHA_H
#define ED_PROVA_PRATICA_PILHA_H

#define novo_elemento(tipo) \
  (tipo *) malloc(sizeof(tipo))
#define MAX(a,b) (a<b)?b:a

// Minha estrutura generica de pilha
typedef struct {
    unsigned int tam;
    unsigned int tamInicial;
    int proximo;
    void **vetor;
} minhaEstrutura;

int init(minhaEstrutura *, unsigned int);

int inserir(minhaEstrutura *, void *);

int remover(minhaEstrutura *, void **);

void delete(minhaEstrutura *);
#else
#warning O arquivo ja foi incluido anteriormente.
#endif //ED_PROVA_PRATICA_PILHA_H
