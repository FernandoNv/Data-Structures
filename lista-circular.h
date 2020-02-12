#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct Elemento{
    struct Elemento* prox;
    struct Aluno* aluno;
}Elemento;

typedef struct Elemento* ListaCircular;

ListaCircular* criaListaCircular();
void liberaListaCircular(ListaCircular* lista);
int tamanhoListaCircular(ListaCircular* lista);
int vazioListaCircular(ListaCircular* lista);
int cheioListaCircular(ListaCircular* lista);
ListaCircular* insereInicioListaCircular(ListaCircular* lista, Aluno* aluno);
ListaCircular* insereFimListaCircular(ListaCircular* lista, Aluno* aluno);
ListaCircular* insereOrdenadoListaCircular(ListaCircular* lista, Aluno* aluno);
ListaCircular* removeInicioListaCircular(ListaCircular* lista);
ListaCircular* removeFimListaCircular(ListaCircular* lista);
ListaCircular* removeMatriculaListaCircular(ListaCircular* lista, int matricula);
Aluno* buscaMatriculaListaCircular(ListaCircular* lista, int matricula);
Aluno* buscaPosicaoListaCircular(ListaCircular* lista, int posicao);
void imprimeListaDupla(ListaCircular* lista);