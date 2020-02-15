#include "lista-circular.h"
#include <stdio.h>
#include <stdlib.h>

ListaCircular* criaListaCircular(){
    ListaCircular* lista = (ListaCircular*) malloc(sizeof(ListaCircular));
    if(lista) (*lista) = NULL;

    return lista;
}


void liberaListaCircular(ListaCircular* lista){
    if(lista && (*lista)){
        Elemento *aux, *atual = (*lista);
        while((*lista) != atual->prox){
            aux = atual;
            atual = atual->prox;
            free(aux->aluno);
            free(aux);
        }
        free(atual->aluno);
        free(atual);
        free(lista);
    }
}


int tamanhoListaCircular(ListaCircular* lista){
    if((!lista) || !(*lista)) return 0;
    int cont = 1;
    Elemento* elemento = (*lista)->prox;
    while(elemento != (*lista)){
        cont++;
        elemento = elemento->prox;
    }

    return cont;
}

int vazioListaCircular(ListaCircular* lista){
    if((!lista) && !(*lista)) return 1;
    return 0;
}

int cheioListaCircular(ListaCircular* lista){
    return 0;
}

ListaCircular* insereInicioListaCircular(ListaCircular* lista, Aluno* aluno){
    if(!lista) return lista;
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    if(!elemento) return lista;
    elemento->aluno = aluno;
    if(!(*lista)){//caso da lista vazia
        (*lista) = elemento;
        elemento->prox = elemento;
    }else{//caso com pelo menos um elemento na lista
        Elemento* aux = (*lista);
        while(aux->prox != (*lista)){
            aux = aux->prox;
        }
        aux->prox = elemento;
        elemento->prox = (*lista);
        (*lista) = elemento;
    }

    return lista;
}

ListaCircular* insereFimListaCircular(ListaCircular* lista, Aluno* aluno){
    if(!lista) return lista;
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    if(!elemento) return lista;
    elemento->aluno = aluno;
    if(!(*lista)){//caso da lista vazia
        return insereInicioListaCircular(lista, aluno);
    }else{//caso com pelo menos um elemento na lista
        Elemento* aux = (*lista);
        while(aux->prox != (*lista)){
            aux = aux->prox;
        }
        aux->prox = elemento;
        elemento->prox = (*lista);
    }

    return lista;
}

ListaCircular* insereOrdenadoListaCircular(ListaCircular* lista, Aluno* aluno){
    if(!lista) return lista;
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    if(!elemento) return lista;
    elemento->aluno = aluno;
    if(!(*lista)){//caso da lista vazia
        return insereInicioListaCircular(lista, aluno);
    }else{//caso com pelo menos um elemento na lista
        Elemento* aux = (*lista);
        if(aluno->matricula > (*lista)->aluno->matricula){
            while(aux->prox != (*lista) && aluno->matricula > aux->prox->aluno->matricula){
                aux = aux->prox;
            }
            if(aux->prox == (*lista))//cheguei no final
                elemento->prox = (*lista);
            else
                elemento->prox = aux->prox;
            aux->prox = elemento;
        }else{//caso q o elemento eh menor do que o primeiro
            while(aux->prox != (*lista)) aux = aux->prox;
            aux->prox = elemento;
            elemento->prox = (*lista);
            (*lista) = elemento;
        }
    }

    return lista;
}

ListaCircular* removeInicioListaCircular(ListaCircular* lista){
    if((!lista) || !(*lista)) return lista;
    if((*lista)->prox == (*lista)){//caso com um único elemento
        free((*lista)->aluno);
        free((*lista));
        (*lista) = NULL;

        return lista;
    }
    Elemento* ultimo = (*lista), *primeiro = (*lista);
    while(ultimo->prox != (*lista)) ultimo = ultimo->prox;
    ultimo->prox = primeiro->prox;
    (*lista) = primeiro->prox;
    free(primeiro->aluno);
    free(primeiro);

    return lista;
}

ListaCircular* removeFimListaCircular(ListaCircular* lista){
    if((!lista) || !(*lista)) return lista;
    if((*lista)->prox == (*lista)){//caso com um único elemento
        return removeInicioListaCircular(lista);
    }
    Elemento* ultimo = (*lista)->prox, *anterior = (*lista);
    while(ultimo->prox != (*lista)){
        ultimo = ultimo->prox;
        anterior = anterior->prox;
    }
    anterior->prox = ultimo->prox;
    free(ultimo->aluno);
    free(ultimo);

    return lista;
}
ListaCircular* removeMatriculaListaCircular(ListaCircular* lista, int matricula){
    if((!lista) || !(*lista) || (matricula < 0)) return lista;
    if(matricula == (*lista)->aluno->matricula) removeInicioListaCircular(lista);
    Elemento* anterior = (*lista), *proximo = (*lista)->prox;
    while(proximo != (*lista) && matricula != proximo->aluno->matricula){
        anterior = proximo;
        proximo = proximo->prox;
    }
    if(proximo == (*lista)) return lista;//matricula nao encontrada
    anterior->prox = proximo->prox;
    free(proximo->aluno);
    free(proximo);

    return lista;
}

Aluno* buscaMatriculaListaCircular(ListaCircular* lista, int matricula){
    if((!lista) || !(*lista) || (matricula < 0)) return NULL;
    if((*lista)->aluno->matricula == matricula) return (*lista)->aluno;
    
    Elemento* elemento = (*lista)->prox;
    while(elemento != (*lista) && matricula != elemento->aluno->matricula) elemento = elemento->prox;
    
    if(elemento == (*lista)) return NULL;
    
    return elemento->aluno;
}
Aluno* buscaPosicaoListaCircular(ListaCircular* lista, int posicao){
    if((!lista) || !(*lista) || (posicao <= 0) || (posicao > tamanhoListaCircular(lista))) return NULL;
    int cont = 1;
    Elemento* elemento = (*lista);
    while(elemento->prox != (*lista) && cont < posicao){
        elemento = elemento->prox;
        cont++;
    }
    if(cont != posicao) 
        return NULL;
    else
        return elemento->aluno;
}

void imprimeListaDupla(ListaCircular* lista){
    if((!lista) || !(*lista)) return;
    Elemento* elemento = (*lista);
    do{
        printf("Nome: %s\n Matricula: %i\n", elemento->aluno->nome, elemento->aluno->matricula);
        for(int i = 0; i < 3; i++) printf("Nota %i: %f\n", i+1, elemento->aluno->notas[i]);
        printf("======================================================================\n");
        elemento = elemento->prox;
    }while(elemento != (*lista));
}