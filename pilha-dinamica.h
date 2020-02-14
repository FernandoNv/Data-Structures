#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

typedef struct Elemento* PilhaDinamica;

typedef struct Elemento{
    struct Aluno dados;
    struct Elemento* prox;
}Elemento;

PilhaDinamica* criaPilhaDinamica();
void liberaPilhaDinamica(PilhaDinamica* pilha);
int tamanhoPilhaDinamica(PilhaDinamica* pilha);
int vazioPilhaDinamica(PilhaDinamica* pilha);
int cheioPilhaDinamica(PilhaDinamica* pilha);
int inserePilhaDinamica(PilhaDinamica* pilha, Aluno aluno);
int retiraPilhaDinamica(PilhaDinamica* pilha);
int buscaPilhaDinamica(PilhaDinamica* pilha, Aluno* aluno);