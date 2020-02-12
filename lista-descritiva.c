#include <stdio.h>
#include <stdlib.h>
#include "lista-descritiva.h"

ListaDescritiva* criaListaDescritiva(){
    ListaDescritiva* lista = (ListaDescritiva*) malloc(sizeof(ListaDescritiva));
    if(!lista) return lista;
    lista->final = NULL;
    lista->inicio = NULL;
    lista->quantidade = 0;

    return lista;
}

void liberaListaDescritiva(ListaDescritiva* lista){
    if(!lista) return;
    Elemento* elemento;
    while(lista->inicio != NULL){
        elemento = lista->inicio;
        lista->inicio = elemento->prox;
        free(elemento->aluno);
        free(elemento);
    }
    free(lista);
}

int tamanhoListaDescritiva(ListaDescritiva* lista){
    if(!lista) return 0;
    return lista->quantidade;
}

ListaDescritiva* insereInicioListaDescritiva(ListaDescritiva* lista, Aluno* aluno){
    if(!lista) return lista;
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    if(!elemento) return lista;
    elemento->aluno = aluno;
    elemento->prox = lista->inicio;

    if(!lista->inicio){
        lista->final = elemento;
    }
    lista->inicio = elemento;
    lista->quantidade++;

    return lista;
}

ListaDescritiva* insereFimListaDescritiva(ListaDescritiva* lista, Aluno* aluno){
    if(!lista) return lista;
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    if(!elemento) return lista;
    elemento->aluno = aluno;
    elemento->prox = NULL;

    if(!lista->inicio) 
        lista->inicio = elemento;
    else
        lista->final->prox = elemento;
    lista->final = elemento;
    lista->quantidade++;

    return lista;
}
ListaDescritiva* insereOrdenadoListaDescritiva(ListaDescritiva* lista, Aluno* aluno);

ListaDescritiva* removeInicioListaDescritiva(ListaDescritiva* lista){
    if((!lista) || (!lista->inicio)) return lista;
    Elemento* elemento = lista->inicio;
    lista->inicio = lista->inicio->prox;
    free(elemento->aluno);
    free(elemento);

    if(!lista->inicio) lista->final = NULL;
    lista->quantidade--;

    return lista;
}
ListaDescritiva* removeFimListaDescritiva(ListaDescritiva* lista){
    if((!lista) || (!lista->inicio)) return lista;
    Elemento* anterior, *final = lista->inicio;
    while(final->prox){
        anterior = final;
        final = final->prox;
    }

    if(final == lista->inicio){
        lista->inicio = NULL;
        lista->final = NULL;
    }else{
        anterior->prox = final->prox;
        lista->final = anterior;
    }

    free(final->aluno);
    free(final);
    lista->quantidade--;

    return lista;
}

ListaDescritiva* removeMatriculaListaDescritiva(ListaDescritiva* lista, int matricula);

void imprimeListaDescritiva(ListaDescritiva* lista){
    if((!lista) || (!lista->inicio)) return;
    Elemento* elemento = lista->inicio;
    do{
        printf("Nome: %s\n Matricula: %i\n", elemento->aluno->nome, elemento->aluno->matricula);
        for(int i = 0; i < 3; i++) printf("Nota %i: %f\n", i+1, elemento->aluno->notas[i]);
        printf("======================================================================\n");
        elemento = elemento->prox;
    }while(elemento);
}