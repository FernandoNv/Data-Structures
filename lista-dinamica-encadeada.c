#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista-dinamica-encadeada.h"

ListaDinamicaEncadeada* criaListaDinamicaEncadeada(){
    return NULL;
}

void liberaListaDinamicaEncadeada(ListaDinamicaEncadeada* lista){
    if(!lista) return;
    free(lista->aluno);
    liberaListaDinamicaEncadeada(lista->prox);
    free(lista);
}

int tamanhoListaDinamicaEncadeada(ListaDinamicaEncadeada* lista){
    if(!lista) return 0;
    return tamanhoListaDinamicaEncadeada(lista->prox) + 1;
}

int cheioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista){
    return 0;
}

int vazioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista){
    if((!lista->aluno) || (!lista)) return 1;
    return 0;
}

ListaDinamicaEncadeada* insereInicioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, Aluno* aluno){
    if((!aluno) && (!lista)) return lista;
    ListaDinamicaEncadeada* aux = malloc(sizeof(ListaDinamicaEncadeada));
    if(!aux) return lista;
    aux->aluno = aluno;
    aux->prox = NULL;
    
    if(!lista) return aux;
    aux->prox = lista;

    return aux;
}

ListaDinamicaEncadeada* insereFimListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, Aluno* aluno){
    if((!aluno) && (!lista)) return lista;
    if(!lista) return insereInicioListaDinamicaEncadeada(lista, aluno);
    ListaDinamicaEncadeada* aux1 = lista;
    ListaDinamicaEncadeada* aux2 = malloc(sizeof(ListaDinamicaEncadeada));
    
    if(!aux2) return lista;
    aux2->aluno = aluno;
    aux2->prox = NULL;

    while(aux1->prox) aux1 = aux1->prox;
    aux1->prox = aux2;

    return lista;
}

ListaDinamicaEncadeada* insereMeioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, Aluno* aluno){
    if((!aluno) && (!lista)) return lista;
    if((!lista) || tamanhoListaDinamicaEncadeada(lista) == 1) return insereInicioListaDinamicaEncadeada(lista, aluno);
    int meio = tamanhoListaDinamicaEncadeada(lista)/2;
    ListaDinamicaEncadeada* aux1 = lista, *aux2 = lista, *aux3 = malloc(sizeof(ListaDinamicaEncadeada));
    if(!aux3) return lista;
    aux3->prox = NULL;
    aux3->aluno = aluno;
    
    aux1 = aux1->prox;
    for(int i = 0; i < meio-1; i++){
        aux2 = aux2->prox;
        aux1 = aux1->prox;
    }

    aux2->prox = aux3;
    aux3->prox = aux1;

    return lista;
}

ListaDinamicaEncadeada* insereOrdenadoListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, Aluno* aluno){
    if((!aluno) && (!lista)) return lista;
    if(!lista) return insereInicioListaDinamicaEncadeada(lista, aluno);
    ListaDinamicaEncadeada *aux1 = lista, *aux2 = malloc(sizeof(ListaDinamicaEncadeada));
    
    if(!aux2) return lista;
    aux2->aluno = aluno;
    aux2->prox = NULL;
    
    while((aux1->prox) && (aluno->matricula > aux1->aluno->matricula)) aux1 = aux1->prox;
    aux2->prox = aux1->prox;
    aux1->prox = aux2;

    return lista;
}

ListaDinamicaEncadeada* removeInicioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista){
    if(!lista) return lista;
    ListaDinamicaEncadeada* aux = lista->prox;
    free(lista->aluno);
    free(lista);

    return aux;
}

ListaDinamicaEncadeada* removeFimListaDinamicaEncadeada(ListaDinamicaEncadeada* lista){
    if(!lista) return lista;
    if(tamanhoListaDinamicaEncadeada(lista) == 1) removeInicioListaDinamicaEncadeada(lista);
    ListaDinamicaEncadeada* aux1 = lista, *aux2;
    while(aux1->prox->prox) aux1 = aux1->prox;
    aux2 = aux1->prox;
    free(aux2->aluno);
    free(aux2);
    aux1->prox = NULL;
    
    return lista;
}
ListaDinamicaEncadeada* removeMeioListaDinamicaEncadeada(ListaDinamicaEncadeada* lista){
    if(!lista) return lista;
    if(tamanhoListaDinamicaEncadeada(lista) == 1) return removeInicioListaDinamicaEncadeada(lista);
    int meio = tamanhoListaDinamicaEncadeada(lista)/2;
    ListaDinamicaEncadeada* aux1 = lista, *aux2 = lista;
    
    aux1 = aux1->prox;
    for(int i = 0; i < meio-1; i++){
        aux2 = aux2->prox;
        aux1 = aux1->prox;
    }

    aux2->prox = aux1->prox;
    free(aux1->aluno);
    free(aux1);

    return lista;
}

ListaDinamicaEncadeada* removeMatriculaListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, int matricula){
    if((!lista) || matricula < 0) return lista;
    if(lista->aluno->matricula == matricula) return removeInicioListaDinamicaEncadeada(lista);
    ListaDinamicaEncadeada* aux1 = lista, *aux2 = lista;
    aux1 = aux1->prox;
    while(aux1){
        if(aux1->aluno->matricula == matricula){
            aux2->prox = aux1->prox;
            free(aux1->aluno);
            free(aux1);
            break;
        }
        aux2 = aux2->prox;
        aux1 = aux1->prox;
    }
    return lista;
}

Aluno* buscaMatriculaListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, int matricula){
    if((!lista) || matricula < 0) return NULL;
    if(lista->aluno->matricula == matricula) return lista->aluno;
    ListaDinamicaEncadeada* aux1 = lista, *aux2 = lista;
    aux1 = aux1->prox;
    while(aux1){
        if(aux1->aluno->matricula == matricula){
            return aux1->aluno;
        }
        aux2 = aux2->prox;
        aux1 = aux1->prox;
    }
    return NULL;
}

Aluno* buscaNomeListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, char* nome){
    if((!lista) || (!nome)) return NULL;
    if(lista->aluno->nome == nome) return lista->aluno;
    ListaDinamicaEncadeada* aux1 = lista, *aux2 = lista;
    aux1 = aux1->prox;
    while(aux1){
        if(aux1->aluno->nome == nome){
            return aux1->aluno;
        }
        aux2 = aux2->prox;
        aux1 = aux1->prox;
    }
    return NULL;
}
Aluno* buscaPosicaoListaDinamicaEncadeada(ListaDinamicaEncadeada* lista, int posicao){
    if((!lista) || posicao <= 0 || posicao > tamanhoListaDinamicaEncadeada(lista)) return NULL;
    ListaDinamicaEncadeada* aux = lista;
    int i = 0;
    while(i < posicao -1){
        aux = aux->prox;
        i++;
    }
    return aux->aluno;
}

void printListaDinamicaEncadeada(ListaDinamicaEncadeada* lista){
    if(!lista) return;
    printf("Nome: %s\n Matricula: %i\n", lista->aluno->nome, lista->aluno->matricula);
    for(int i = 0; i < 3; i++) printf("Nota %i: %f\n", i+1, lista->aluno->notas[i]);
    printf("======================================================================\n");
    return printListaDinamicaEncadeada(lista->prox);
}