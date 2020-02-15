#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

#define MAX 100

typedef struct PilhaEstatica{
    int quantidade;
    struct Aluno dados[MAX];
}PilhaEstatica;

PilhaEstatica* criaPilhaEstatica();
void liberaPilhaEstatica(PilhaEstatica* pilha);
int tamanhoPilhaEstatica(PilhaEstatica* pilha);
int vazioPilhaEstatica(PilhaEstatica* pilha);
int cheioPilhaEstatica(PilhaEstatica* pilha);
int inserePilhaEstatica(PilhaEstatica* pilha, Aluno aluno);
int removePilhaEstatica(PilhaEstatica* pilha);
int buscaPilhaEstatica(PilhaEstatica* pilha, Aluno* aluno);