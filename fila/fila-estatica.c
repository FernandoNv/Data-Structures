#include <stdlib.h>
#include <stdio.h>
#include "fila-estatica.h"

Fila* criaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila){
        fila->inicio = 0;
        fila->final = 0;
        fila->quantidade = 0;
    }

    return fila;
}
void liberaFila(Fila* fila){
    free(fila);
}
int tamanhoFila(Fila* fila){
    if(!fila) return -1;
    return fila->quantidade;
}

int cheioFila(Fila* fila){
    if(!fila) return -1;
    if(fila->quantidade == MAX) return 1;
    return 0;
}
int vazioFila(Fila* fila){
    if(!fila) return -1;
    if(fila->quantidade == 0) return 1;
    return 0;
}

int insereFila(Fila* fila, Aluno aluno){
    if((!fila) || cheioFila(fila)) return 0;
    fila->dados[fila->final] = aluno;
    fila->final = (fila->final+1)%MAX;
    fila->quantidade++;

    return 1;
}
int removeFila(Fila* fila){
    if((!fila) || vazioFila(fila)) return 0;
    fila->inicio = (fila->inicio+1)%MAX;
    fila->quantidade--;

    return 1;
}

int consultaFila(Fila* fila, Aluno* aluno){
    if((!fila) || vazioFila(fila) || (!aluno)) return 0;
    (*aluno) = fila->dados[fila->inicio];
    
    return 1;
}

void imprimeFila(Fila* fila){
	if(!fila) return;
	for(int i = 0; i < fila->quantidade; i++){
		printf("Aluno: %s \nMatricula: %i \n", fila->dados[i].nome, fila->dados[i].matricula);
		for(int j = 0; j < 3; j++){
			printf("Nota %i \n %f \n", j+1, fila->dados[i].notas[j]);
		}
		printf("--------------------------------------------------\n");
	}
}