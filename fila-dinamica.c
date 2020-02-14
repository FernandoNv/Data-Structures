#include <stdlib.h>
#include <stdio.h>
#include "fila-dinamica.h"

FilaDinamica* criaFilaDinamica(){
    FilaDinamica* fila = (FilaDinamica*) malloc(sizeof(FilaDinamica));
    if(fila){
        fila->inicio = NULL;
        fila->final = NULL;
        fila->quantidade = 0;
    }

    return fila;
}

void liberaFilaDinamica(FilaDinamica* fila){
    if(!fila) return;
    Elemento* elemento;
    while(fila->inicio){
        elemento = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(elemento);
    }

    free(fila);
}

int tamanhoFilaDinamica(FilaDinamica* fila){
    if(!fila) return -1;
    return fila->quantidade;
}

int cheioFilaDinamica(FilaDinamica* fila){
    return 0;
}

int vazioFilaDinamica(FilaDinamica* fila){
    if(!fila) return -1;
    if(fila->quantidade == 0) return 1;
    return 0;
}

int insereFilaDinamica(FilaDinamica* fila, Aluno aluno){
    if(!fila)  return 0;
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    if(!elemento) return 0;
    elemento->aluno = aluno;
    elemento->prox = NULL;
    if(!fila->inicio) 
        fila->inicio = elemento;
    else
        fila->final->prox = elemento;
    fila->final = elemento;
    fila->quantidade++;

    return 1;
}

void imprimeFilaDinamica(FilaDinamica* fila){
    if(!fila) return;
    Elemento* elemento = fila->inicio;
	while(elemento){
        printf("Aluno: %s \nMatricula: %i \n", elemento->aluno.nome, elemento->aluno.matricula);
		for(int j = 0; j < 3; j++){
			printf("Nota %i \n %f \n", j+1, elemento->aluno.notas[j]);
		}
		printf("--------------------------------------------------\n");
        elemento = elemento->prox;
    }
}

int removeFilaDinamica(FilaDinamica* fila){
    if(!(fila) || !(fila->inicio)) return 0;
    Elemento* elemento = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if(!fila->inicio) fila->final = NULL;
    free(elemento);
    fila->quantidade--;

    return 1;
}

int buscaFilaDinamica(FilaDinamica* fila, Aluno* aluno){
    if((!fila) || (!aluno) || !(fila->inicio)) return 0;
    (*aluno) = fila->inicio->aluno;

    return 1;
}