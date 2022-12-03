#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "ListaLigada.h"

int main() {

    int i; // variavel auxiliar para todos os for
    minhaEstrutura minhaEstruturaInt; // Minha primeira estrutura (de inteiros)
    init(&minhaEstruturaInt, 9); // Inicializa a estrutura para armazenar somente 2 elementos

    for(i=100; i<110; i++) { // Vamos colocar dados na estrutura
        int *elem = novo_elemento(int); // Criando o elemento que sera colocado naestrutura
        // Precisa verificar se conseguiu alocar memoria para colocar o elemento (prafacilitar aqui, nao vou verificar)*elem = i;
        if (!inserir(&minhaEstruturaInt, (void *)elem)) { // Coloca o elemento naestrutura e verifica se conseguiu realizar a operacao
            printf("Nao foi possivel colocar o elemento %d na estrutura. minhaEstruturacheia!\n", i);
        }
        else {
            printf("Elemento %d colocado na posicao %d da estrutura (tamanhoEstrutura=%d).\n", i, minhaEstruturaInt.proximo, minhaEstruturaInt.tam);
        }
    }
    void *elemInt;
    // Retirando elementos da estrutura
    for(i=1;i<=30;i+=4) {
        if (!remover(&minhaEstruturaInt,&elemInt)) {
            printf("Pilha vazia!!!\n");
        }
        else {
            printf("Retirado: [minhaEstruturaInt] %d (tamanhoEstrutura=%d).\n", *(int*)elemInt, minhaEstruturaInt.tam);
            // O elemento retirado da estrutura, quando nao for ser mais utilizadosprecisa ter a memoria liberada
            free(elemInt);
        }
    }
    delete(&minhaEstruturaInt);

    //--*--

    ListaLigada minhaLista;
    initLista(&minhaLista);

    for(i=100; i<110; i++) { // Vamos colocar dados na lista
        int *elem = novo_elemento(int); // Criando o elemento (inteiro) que sera colocado na lista
        // Precisa verificar se conseguiu alocar memoria para colocar o elemento (pra facilitar aqui, nao vou verificar)
        *elem = i;
        if (!inserirComeco(&minhaLista, (void *)elem)) { // Coloca o elemento na lista e verifica se conseguiu realizar a operacao
            printf("Nao foi possivel colocar o elemento %d na lista. Memoria cheia!\n", i);
        }
        else {
            printf("Elemento %d colocado na lista. [Primeiro=%p, Ultimo=%p]\n", i,
                   minhaLista.primeiro, minhaLista.ultimo);
        }
    }
    // Retirando elementos da lista
    for(i=1;i<=30;i+=2) {
        elemInt=removerComeco(&minhaLista); // Solicita a remocao de um elemento da lista
        if (elemInt==NULL) { // A lista nao tem elementos para remover?
            printf("Nao existem mais elementos a serem removidos.\n");
            break; // Nao tem mais elementos a retirar da lista, nao adianta continuar
        }
        else {
            printf("Retirado da Lista: %d. [Primeiro=%p, Ultimo=%p]\n", *(int *)elemInt,
                   minhaLista.primeiro, minhaLista.ultimo);
            // O elemento retirado da lista, quando nao for ser mais utilizados precisa ter a memoria liberada
            free(elemInt);
        }
    }
    deleteLista(&minhaLista); // Garantindo que nenhum memoria alocada ira ficarcperdida

    return 0;
}

