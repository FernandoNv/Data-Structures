#include <stdlib.h>
#include <stdio.h>
#include "lista-dinamica-encadeada-dupla.h"

ListaDupla* criaListaDupla(){
    ListaDupla* lista = (ListaDupla*) malloc(sizeof(ListaDupla));
    if(!lista) (*lista) =  NULL;
    return lista;
}

void liberaAux(Elemento* elemento){
    if(!elemento) return;
    Elemento* prox = elemento->prox;
    free(elemento->aluno);
    free(elemento);

    return liberaAux(prox);
}

void liberaListaDupla(ListaDupla* lista){
    if(!lista) return;
    Elemento* elemento = (*lista);//ponteiro do primeiro elemento
    free(lista);
    return liberaAux(elemento);
}

int tamanhoAux(Elemento* elemento){
    if(!elemento) return 0;
    return tamanhoAux(elemento->prox) + 1;
}

int tamanhoListaDupla(ListaDupla* lista){
    if(!lista) return 0;
    //ponteiro do primeiro elemento
    return tamanhoAux((*lista));
}

int vazioListaDupla(ListaDupla* lista){
    if(!lista) return 1;
    if(*lista) return 0;
    return 1;
}

int cheioListaDupla(ListaDupla* lista){
    return 0;
}
