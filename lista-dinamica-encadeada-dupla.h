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
ListaDupla* insereInicioListaDupla(ListaDupla* lista, Aluno* aluno);
ListaDupla* insereMeioListaDupla(ListaDupla* lista, Aluno* aluno);
ListaDupla* insereFimListaDupla(ListaDupla* lista, Aluno* aluno);
ListaDupla* insereOrdenadoListaDupla(ListaDupla* lista, Aluno* aluno);
ListaDupla* removeInicioListaDupla(ListaDupla* lista);
ListaDupla* removeFimListaDupla(ListaDupla* lista);
ListaDupla* removeMatriculaListaDupla(ListaDupla* lista, int matricula);
Aluno* buscaMatriculaListaDupla(ListaDupla* lista, int matricula);
Aluno* buscaPosicaoListaDupla(ListaDupla* lista, int posicao);
void imprimeListaDupla(ListaDupla* lista);