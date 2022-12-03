//
// Created by leoro on 01/12/2022.
//

#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

// Funcao para inicializacao da pilha
int init(minhaEstrutura *pilha, unsigned int tamanho) {
    int retorno=1;
    // Inicializa o meu vetor da estrutura, alocando memoria para a quantidade deelementos indicada
    pilha->vetor = (void **) malloc(tamanho*sizeof(void *));
    if (pilha->vetor == NULL) {
        retorno=0;
    }
    else {
        // Inicializa as demais variaveis da minha estrutura
        pilha->tam = tamanho;
        pilha->tamInicial = tamanho;
        pilha->proximo = -1;
    }
    return retorno;
}
// Funcao para colocar elementos na pilha
int inserir(minhaEstrutura *pilha, void *valor) {
    int retorno=1;
    if (pilha->proximo != pilha->tam - 1) { // Tem espaco disponivel?
        pilha->proximo++;
        pilha->vetor[pilha->proximo] = valor;
    }
    else {
        void *tmp = realloc(pilha->vetor, 2*pilha->tam*sizeof(void *)); // Tenta dobraro espaco para armazenar os dados na pilha
        if (tmp != NULL) { // Verificando se foi possivel aumentar o tamanho da pilha
            printf("Estrutura redimensionada de %d para %d elementos.\n", pilha->tam,
                   pilha->tam*2);
            pilha->vetor = tmp; // Armazena o novo endereco para a pilha aumentada
            pilha->tam *=2; // Armazena o novo tamanho da pilha
            retorno=inserir(pilha, valor); // Chama a funcao para inserir o elemento
        }
        else {
            //Informa o desenvolvedor que nao foi possivel colocar o elemento na pilha(retornando 0 [falso]) pois a pilha esta cheia e nao foi possivel aumentar seutamanho
            retorno=0;
        }
    }
    return retorno;
}
// Funcao para retirar elementos da pilha
int remover(minhaEstrutura *pilha, void **valor) {
    int retorno=1;
    if (pilha->proximo != -1) { // Tem pelo menos um elemento na pilha?
        *valor=pilha->vetor[pilha->proximo];
        pilha->proximo--;
        if (pilha->tam>pilha->tamInicial && pilha->proximo <= pilha->tam/4) {
            // Autilizacao da pilha eh de menos de 1/4?
            void *tmp=realloc(pilha->vetor, MAX(pilha->tam/2,pilha->tamInicial)*sizeof(void *));
            // Tenta diminuir pela metade o espaco para armazenaros dados na pilha
            if (tmp != NULL) { // Verificando se foi possivel reduzir o tamanho da pilha(nao eh pra falhar, mas por garantia...)
                printf("Estrutura redimensionada de %d para %d elementos.\n", pilha->tam,
                       MAX(pilha->tam/2,pilha->tamInicial));
                pilha->vetor = tmp; // Armazena o novo endereco para a pilha reduzida
                pilha->tam = MAX(pilha->tam/2,pilha->tamInicial); // Armazena o novo tamanhoda pilha
            }
            //else - Mantem o endereco da pilha alocada e nao faz nenhuma mudanca
        }
    }
    else { // Informa o desenvolvedor que nao foi possivel retornar um elemento(retornando 0 [falso]) pois a pilha esta vazia
        retorno=0;
    }
    return retorno;
}
// Libera toda a memoria utilizada pela pilha
void delete(minhaEstrutura *pilha) {
    // Se a pilha n o est  vazia libera a memoria de todos os elementos alocados/colocados nela
    while (pilha->proximo != -1) {
        printf("Liberando os elementos ainda na estrutura: [pos=%d,val=%p]\n", pilha->proximo,
               pilha->vetor[pilha->proximo]);
        free(pilha->vetor[pilha->proximo]);
        pilha->proximo--;
    }
    free(pilha->vetor); // libera a memoria alocada para guardar os elementos dapilha
}