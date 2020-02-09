#include <stdio.h>
#include <stdlib.h>
#include "lista-estatica.h"

ListaEstatica* criaListaEstatica(){
	ListaEstatica* lista = (ListaEstatica*) malloc(sizeof(ListaEstatica));
	if (lista) {
		lista->quantidade = 0;
	}

	return lista;
}

int tamanhoListaEstatica(ListaEstatica* lista){
	if (!lista) return -1;

	return lista->quantidade;
}

int cheioListaEstatica(ListaEstatica* lista){
	if (!lista) return -1;
	if (lista->quantidade == MAX) return 1;

	return 0;
}

int vazioListaEstatica(ListaEstatica* lista){
	if (!lista) return -1;
	if (lista->quantidade == 0) return 1;

	return 0;
}

int insereFimListaEstatica(ListaEstatica* lista, Aluno* aluno){
	if(cheioListaEstatica(lista) || (!lista)) return 0;
	if(lista -> quantidade == 0) return insereInicioListaEstatica(lista, aluno);

	lista->dados[lista->quantidade] = aluno;
	lista->quantidade++;

	return 1;
}

int insereInicioListaEstatica(ListaEstatica* lista, Aluno* aluno){
	if(cheioListaEstatica(lista) || (!lista)) return 0;
	if(lista->quantidade > 0){
		for(int i = lista->quantidade; i >= 0; i--) lista->dados[i+1] = lista->dados[i];
	}
	lista->dados[0] = aluno;
	lista->quantidade++;

	return 1;
}

int insereMeioListaEstatica(ListaEstatica* lista, Aluno* aluno){
	if(cheioListaEstatica(lista) || (!lista)) return 0;
	if(lista -> quantidade == 0) return insereInicioListaEstatica(lista, aluno);

	int meio = lista->quantidade/2;
	for(int i = lista->quantidade; i >= meio; i--) lista->dados[i+1] = lista->dados[i];
	lista->dados[meio] = aluno;
	lista->quantidade++;

	return 1;
}

int insereOrdenadoListaEstatica(ListaEstatica* lista, Aluno* aluno){
	if(cheioListaEstatica(lista) || (!lista)) return 0;
	if(lista -> quantidade == 0) return insereInicioListaEstatica(lista, aluno);

	int i = 0;
	while((i < lista->quantidade) && (aluno->matricula > lista->dados[i]->matricula)) i++;
	for(int j = lista->quantidade; j >= i; j--) lista->dados[j+1] = lista->dados[j];
	lista->dados[i] = aluno;
	lista->quantidade++;

	return 1;
}

Aluno* removeFimListaEstatica(ListaEstatica* lista){
	if((!lista) || (vazioListaEstatica(lista))) return NULL;
	Aluno* aux = lista->dados[lista->quantidade-1];
	lista->quantidade--;
	return aux;
}


Aluno* removeInicioListaEstatica(ListaEstatica* lista){
	if((!lista) || (vazioListaEstatica(lista))) return NULL;
	Aluno* aluno = lista->dados[0];
	for(int i = 1; i < lista->quantidade; i++) lista->dados[i-1] = lista->dados[i];
	lista->quantidade--;

	return aluno;
}


Aluno* removeMeioListaEstatica(ListaEstatica* lista){
	if((!lista) || (vazioListaEstatica(lista))) return NULL;
	int meio = (lista->quantidade/2);
	Aluno* aluno = lista->dados[meio];

	for(int i = meio+1; i < lista->quantidade; i++) lista->dados[i-1] = lista->dados[i];
	lista->quantidade--;

	return aluno;
}

Aluno* removeMatriculaListaEstatica(ListaEstatica* lista, int matricula){
	if((!lista) || (vazioListaEstatica(lista))) return NULL;
	int i = 0;
	while(i < lista->quantidade && matricula != lista->dados[i]->matricula) i++;

	if(i == lista->quantidade) return NULL;
	
	Aluno* aluno = lista->dados[i];

	for(int j = i + 1; j < lista->quantidade; j++) lista->dados[j-1] = lista->dados[j];
	lista->quantidade--;

	return aluno;
}


Aluno* buscaPosicaoListaEstatica(ListaEstatica* lista, int posicao){
	if((!lista) || (vazioListaEstatica(lista)) || (posicao > lista->quantidade) || (posicao <= 0)) return NULL;
	return lista->dados[posicao-1];
}

Aluno* buscaMatriculaListaEstatica(ListaEstatica* lista, int matricula){
	if((!lista) || (vazioListaEstatica(lista)) || (matricula < 0)) return NULL;
	int i = 0;
	while(i < lista->quantidade && matricula != lista->dados[i]->matricula) i++;
	if(i == lista->quantidade) return NULL;

	return lista->dados[i];
}

Aluno* buscaNomeListaEstatica(ListaEstatica* lista, char* nome){
	if((!lista) || (vazioListaEstatica(lista)) || (nome == NULL)) return NULL;
	int i = 0;
	while(i < lista->quantidade && nome != lista->dados[i]->nome) i++;
	if(i == lista->quantidade) return NULL;

	return lista->dados[i];
}

void liberaListaEstatica(ListaEstatica* lista){
	free(lista);
}

void imprimeListaEstatica(ListaEstatica* lista){
	if(!lista) return;
	for(int i = 0; i < lista->quantidade; i++){
		printf("Aluno: %s \nMatricula: %i \n", lista->dados[i]->nome, lista->dados[i]->matricula);
		for(int j = 0; j < 3; j++){
			printf("Nota %i \n %f \n", j+1, lista->dados[i]->notas[j]);
		}
		printf("--------------------------------------------------\n");
	}
}
