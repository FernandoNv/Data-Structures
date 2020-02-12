#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct Elemento{
    Aluno* aluno;
    struct Elemento* prox;
}Elemento;

typedef struct ListaDescritiva{
    struct Elemento *inicio;
    struct Elemento *final;
    int quantidade;
}ListaDescritiva;

ListaDescritiva* criaListaDescritiva();
void liberaListaDescritiva(ListaDescritiva* lista);
int tamanhoListaDescritiva(ListaDescritiva* lista);
ListaDescritiva* insereInicioListaDescritiva(ListaDescritiva* lista, Aluno* aluno);
ListaDescritiva* insereFimListaDescritiva(ListaDescritiva* lista, Aluno* aluno);
ListaDescritiva* insereOrdenadoListaDescritiva(ListaDescritiva* lista, Aluno* aluno);
ListaDescritiva* removeInicioListaDescritiva(ListaDescritiva* lista);
ListaDescritiva* removeFimListaDescritiva(ListaDescritiva* lista);
ListaDescritiva* removeMatriculaListaDescritiva(ListaDescritiva* lista, int matricula);
void imprimeListaDescritiva(ListaDescritiva* lista);