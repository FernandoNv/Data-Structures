#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct ListaDinamicaEncadeada{
    Aluno* aluno;
    struct ListaDinamicaEncadeada* prox;
}ListaDinamicaEncadeada;

ListaDinamicaEncadeada* criaListaDinamicaEncadeada();
void liberaListaDinamicaEncadeada(ListaDinamicaEncadeada* lista);
int tamanhoListaDinamicaEncadeada(ListaDinamicaEncadeada* lista);
int cheioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista);
int vazioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista);
ListaDinamicaEncadeada* insereInicioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, Aluno* aluno);
ListaDinamicaEncadeada* insereFimListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, Aluno* aluno);
ListaDinamicaEncadeada* insereMeioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, Aluno* aluno);
ListaDinamicaEncadeada* insereOrdenadoListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, Aluno* aluno);
ListaDinamicaEncadeada* removeInicioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista);
ListaDinamicaEncadeada* removeFimListaDinamicaEncadeada(ListaDinamicaEncadeada* lista);
ListaDinamicaEncadeada* removeMeioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista);
ListaDinamicaEncadeada* removeMatriculaListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, int matricula);
Aluno* buscaMatriculaListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, int matricula);
Aluno* buscaNomeListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, char* nome);
Aluno* buscaPosicaoListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, int posicao);
void printListaDinamicaEncadeada(ListaDinamicaEncadeada* lista);