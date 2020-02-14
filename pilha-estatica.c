#include <stdlib.h>
#include <stdio.h>
#include "pilha-estatica.h"

PilhaEstatica* criaPilhaEstatica(){
    PilhaEstatica* pilha = (PilhaEstatica*) malloc(sizeof(PilhaEstatica));
    if(pilha) pilha->quantidade = 0;
    
    return pilha;
}


void liberaPilhaEstatica(PilhaEstatica* pilha){
    free(pilha);
}

int tamanhoPilhaEstatica(PilhaEstatica* pilha){
    if(!pilha) return -1;
    return pilha->quantidade;
}

int vazioPilhaEstatica(PilhaEstatica* pilha){
    if(!pilha) return -1;
    return pilha->quantidade == 0;
}

int cheioPilhaEstatica(PilhaEstatica* pilha){
    if(!pilha) return -1;
    return pilha->quantidade == MAX;
}

int inserePilhaEstatica(PilhaEstatica* pilha, Aluno aluno){
    if(!(pilha) || (cheioPilhaEstatica(pilha))) return 0;
    pilha->dados[pilha->quantidade] = aluno;
    pilha->quantidade++;

    return 1;
}

int removePilhaEstatica(PilhaEstatica* pilha){
    if(!pilha || vazioPilhaEstatica(pilha)) return 0;
    pilha->quantidade--;
    
    return 1;
}

int buscaPilhaEstatica(PilhaEstatica* pilha, Aluno* aluno){
    if(!pilha || vazioPilhaEstatica(pilha)) return 0;
    (*aluno) = pilha->dados[pilha->quantidade-1];

    return 1;
}