#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

#define MAX 100

typedef struct Fila{
    int inicio, final, quantidade;
    struct Aluno dados[MAX];
}Fila;

Fila* criaFila();
void liberaFila(Fila* fila);
int tamanhoFila(Fila* fila);
int cheioFila(Fila* fila);
int vazioFila(Fila* fila);
int insereFila(Fila* fila, Aluno aluno);
int removeFila(Fila* fila);
int consultaFila(Fila* fila, Aluno* aluno);
void imprimeFila(Fila* fila);