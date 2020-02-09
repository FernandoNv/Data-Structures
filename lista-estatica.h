#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define MAX 100

typedef struct listaEstatica {
	int quantidade;
	struct Aluno* dados[MAX];
}ListaEstatica;

ListaEstatica* criaListaEstatica();
int tamanhoListaEstatica(ListaEstatica* lista);
int cheioListaEstatica(ListaEstatica* lista);
int vazioListaEstatica(ListaEstatica* lista);
int insereFimListaEstatica(ListaEstatica* lista, Aluno* aluno);
int insereInicioListaEstatica(ListaEstatica* lista, Aluno* aluno);
int insereMeioListaEstatica(ListaEstatica* lista, Aluno* aluno);
int insereOrdenadoListaEstatica(ListaEstatica* lista, Aluno* aluno);
Aluno* removeFimListaEstatica(ListaEstatica* lista);
Aluno* removeInicioListaEstatica(ListaEstatica* lista);
Aluno* removeMeioListaEstatica(ListaEstatica* lista);
Aluno* removeMatriculaListaEstatica(ListaEstatica* lista, int matricula);
Aluno* buscaPosicaoListaEstatica(ListaEstatica* lista, int posicao);
Aluno* buscaMatriculaListaEstatica(ListaEstatica* lista, int matricula);
Aluno* buscaNomeListaEstatica(ListaEstatica* lista, char* nome);
void liberaListaEstatica(ListaEstatica* lista);
void imprimeListaEstatica(ListaEstatica* lista);