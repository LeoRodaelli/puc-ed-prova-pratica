#ifndef ED_PROVA_PRATICA_LISTA_H
#define ED_PROVA_PRATICA_LISTA_H


struct nodeLista{
    struct nodePilha *data;
    struct nodeLista *next;
};

void insertLista(struct nodeLista **root, int totalCopos);
void printLista(struct nodeLista *searcher);

#endif //ED_PROVA_PRATICA_LISTA_H
