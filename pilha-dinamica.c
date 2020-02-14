#include <stdlib.h>
#include <stdio.h>
#include "pilha-dinamica.h"

PilhaDinamica* criaPilhaDinamica(){
    PilhaDinamica* pilha = (PilhaDinamica*) malloc(sizeof(PilhaDinamica));
    if(pilha){
        (*pilha) = NULL;
    }

    return pilha;
}
void liberaPilhaDinamica(PilhaDinamica* pilha){
    if(pilha){
        Elemento* elemento;
        while((*pilha)){
            elemento = (*pilha);
            (*pilha) = (*pilha)->prox;
            free(elemento);
        }
        free(pilha);
    }
}
int tamanhoPilhaDinamica(PilhaDinamica* pilha){
    if(!pilha) return -1;
    int cont = 0;
    Elemento* elemento = (*pilha);
    while(elemento){
        cont++;
        elemento = elemento->prox;
    }
    
    return cont;
}
int vazioPilhaDinamica(PilhaDinamica* pilha){
    if(!pilha) return -1;
    return (*pilha) == NULL;
}

int cheioPilhaDinamica(PilhaDinamica* pilha){
    return 0;
}

int inserePilhaDinamica(PilhaDinamica* pilha, Aluno aluno){
    if(!pilha) return 0;
    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    if(!elemento) return 0;
    elemento->dados = aluno;
    elemento->prox = (*pilha);
    (*pilha) = elemento;

    return 1;
}
int retiraPilhaDinamica(PilhaDinamica* pilha){
    if((!pilha) || !(*pilha)) return 0;
    Elemento* elemento = (*pilha);
    (*pilha) = (*pilha)->prox;
    free(elemento);

    return 1;
}
int buscaPilhaDinamica(PilhaDinamica* pilha, Aluno* aluno){
    if((!pilha) || !(*pilha)) return 0;
    (*aluno) = (*pilha)->dados;
        
    return 1;
}