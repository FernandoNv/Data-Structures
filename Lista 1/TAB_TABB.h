#ifndef TAB_TABB_H_INCLUDED
#define TAB_TABB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    int cor;
    struct ab *esq, *dir;
}TAB;

typedef struct abb{
    int info;
    struct ab *esq, *dir;
}TABB;

TAB* cria_ab(int x, TAB* e, TAB* d);
void imprime_ab(TAB *t);
void libera_ab(TAB* t);
TAB* busca_ab(int e, TAB* t);
TAB* busca_abb(int e, TAB* t);
TAB* insere_abb(int e, TAB* t);
TAB* retira_abb(int e, TAB *t);

#endif
