#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista-dinamica-encadeada-dupla.h"

ListaDupla* criaListaDupla(){
    ListaDupla* lista = (ListaDupla*) malloc(sizeof(ListaDupla));
    if(!lista) (*lista) =  NULL;
    return lista;
}

void liberaAux(Elemento* elemento){
    if(!elemento) return;
    Elemento* prox = elemento->prox;
    free(elemento->aluno);
    free(elemento);

    return liberaAux(prox);
}

void liberaListaDupla(ListaDupla* lista){
    if(!lista) return;
    Elemento* elemento = (*lista);//ponteiro do primeiro elemento
    free(lista);
    return liberaAux(elemento);
}

int tamanhoAux(Elemento* elemento){
    if(!elemento) return 0;
    return tamanhoAux(elemento->prox) + 1;
}

int tamanhoListaDupla(ListaDupla* lista){
    if(!lista) return 0;
    //ponteiro do primeiro elemento
    return tamanhoAux((*lista));
}

int vazioListaDupla(ListaDupla* lista){
    if(!lista) return 1;
    if(*lista) return 0;
    return 1;
}

int cheioListaDupla(ListaDupla* lista){
    return 0;
}

ListaDupla* insereInicioListaDupla(ListaDupla* lista, Aluno* aluno){
    if((!lista) || (!aluno)) return lista;
    Elemento* elemento = (*lista); //primeiro elemento da lista
    Elemento* newElemento = (Elemento*) malloc(sizeof(Elemento));
    if(!newElemento) return lista;
    
    newElemento->ant = NULL;
    newElemento->prox = elemento;
    newElemento->aluno = aluno;
    if(elemento){
        elemento->ant = newElemento;
    }
    (*lista) = newElemento;
    return lista;
}

ListaDupla* insereMeioListaDupla(ListaDupla* lista, Aluno* aluno);

ListaDupla* insereFimListaDupla(ListaDupla* lista, Aluno* aluno){
    if(!lista) return lista;
    if(!(*lista)) return insereInicioListaDupla(lista, aluno);
    Elemento* atual = (*lista), *newElemento = (Elemento*) malloc(sizeof(Elemento));
    if(!newElemento) return lista;
    newElemento->aluno = aluno;
    newElemento->prox = NULL;
    
    while(atual->prox) atual = atual->prox;

    atual->prox = newElemento;
    newElemento->ant = atual;

    return lista;
}

ListaDupla* insereOrdenadoListaDupla(ListaDupla* lista, Aluno* aluno){
    if(!lista) return lista;
    if(!(*lista) || (aluno->matricula < (*lista)->aluno->matricula)) return insereInicioListaDupla(lista, aluno);
    
    Elemento* atual = (*lista), *newElemento = (Elemento*) malloc(sizeof(Elemento));
    if(!newElemento) return lista;
    
    newElemento->aluno = aluno;
    
    while(atual->prox && aluno->matricula > atual->aluno->matricula) atual = atual->prox;
    if(aluno->matricula > atual->aluno->matricula){
        newElemento->ant = atual;
        newElemento->prox = atual->prox;
        atual->prox = newElemento;
    }else{
        newElemento->prox = atual;
        newElemento->ant = atual->ant;
        atual->ant->prox = newElemento;
        atual->ant = newElemento;
    }
    
    return lista;
}

ListaDupla* removeInicioListaDupla(ListaDupla* lista){
    if((!lista) || vazioListaDupla(lista)) return lista;
    if(tamanhoListaDupla(lista) == 1){
        free((*lista)->aluno);
        free((*lista));
        (*lista) = NULL;
        return lista;
    }
    Elemento* atual = (*lista)->prox, *aux = (*lista);
    atual->ant = NULL;
    free(aux->aluno);
    free(aux);

    (*lista) = atual;
    return lista;
}

ListaDupla* removeFimListaDupla(ListaDupla* lista){
    if((!lista) || vazioListaDupla(lista)) return lista;
    if(tamanhoListaDupla(lista) == 1) return removeInicioListaDupla(lista);
    
    Elemento* elemento = (*lista);
    while(elemento->prox) elemento = elemento->prox;
    
    elemento->ant->prox = NULL;
    free(elemento->aluno);
    free(elemento);

    return lista;
}
ListaDupla* removeMatriculaListaDupla(ListaDupla* lista, int matricula){
    if((!lista) || vazioListaDupla(lista) || matricula < 0) return lista;
    if((*lista)->aluno->matricula == matricula) return removeInicioListaDupla(lista);

    Elemento* elemento = (*lista);
    while(elemento && matricula != elemento->aluno->matricula) elemento = elemento->prox;
    if(!elemento) return lista;
    
    if(!elemento->prox){
        //caso esteja no final da lista
        elemento->ant->prox = NULL;
    }else{
        //caso generico
        elemento->ant->prox = elemento->prox;
        elemento->prox->ant = elemento->ant;
    }
    

    free(elemento->aluno);
    free(elemento);

    return lista;
}

Aluno* buscaMatriculaListaDupla(ListaDupla* lista, int matricula){
    if((!lista) || vazioListaDupla(lista) || matricula < 0) return NULL;
    Elemento* aux1 = (*lista);
    while(aux1){
        if(aux1->aluno->matricula == matricula){
            return aux1->aluno;
        }
        aux1 = aux1->prox;
    }
    return NULL;
}

Aluno* buscaPosicaoListaDupla(ListaDupla* lista, int posicao){
    if((!lista) || posicao <= 0 || posicao > tamanhoListaDupla(lista)) return NULL;
    Elemento* aux = (*lista);
    int i = 0;
    while(i < posicao -1){
        aux = aux->prox;
        i++;
    }
    return aux->aluno;
}



void imprimeAux(Elemento* elemento){
    if(!elemento) return;
    printf("Nome: %s\n Matricula: %i\n", elemento->aluno->nome, elemento->aluno->matricula);
    for(int i = 0; i < 3; i++) printf("Nota %i: %f\n", i+1, elemento->aluno->notas[i]);
    printf("======================================================================\n");
    return imprimeAux(elemento->prox);
}
void imprimeListaDupla(ListaDupla* lista){
    if((!lista) || !(*lista)) return;
    imprimeAux(*lista);
}