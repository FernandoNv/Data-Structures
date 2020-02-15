#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

typedef struct FilaDinamica{
    int quantidade;
    struct Elemento* inicio;
    struct Elemento* final;
}FilaDinamica;

typedef struct Elemento{
    struct Aluno aluno;
    struct Elemento* prox;
}Elemento;

FilaDinamica* criaFilaDinamica();
void liberaFilaDinamica(FilaDinamica* fila);
int tamanhoFilaDinamica(FilaDinamica* fila);
int cheioFilaDinamica(FilaDinamica* fila);
int vazioFilaDinamica(FilaDinamica* fila);
int insereFilaDinamica(FilaDinamica* fila, Aluno aluno);
int removeFilaDinamica(FilaDinamica* fila);
int buscaFilaDinamica(FilaDinamica* fila, Aluno* aluno);
void imprimeFilaDinamica(FilaDinamica* fila);