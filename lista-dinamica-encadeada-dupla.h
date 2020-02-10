#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

typedef struct Elemento* ListaDupla;

typedef struct Elemento{
    struct Elemento* ant;
    struct Elemento* prox;
    struct Aluno* aluno;
}Elemento;

ListaDupla* criaListaDupla();
void liberaListaDupla(ListaDupla* lista);
int tamanhoListaDupla(ListaDupla* lista);
int vazioListaDupla(ListaDupla* lista);
int cheioListaDupla(ListaDupla* lista);