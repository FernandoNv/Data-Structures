#ifndef TAAVL_H_INCLUDED
#define TAAVL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct no{
    int info;
    struct no*  esq;
    struct no*  dir;
    int alt;
}no;


void libera(no* t);
no* busca(int e, no* t );
no * retira(int x, no *T);
no* insere(int e, no* t);
static int calc_alt( no* n );
static int max( int l, int r);
static int min( int l, int r);
static no* rot_dir( no* k2 );
static no* rot_esq( no* k1 );
static no* rot_esq_dir( no* k3 );
static no* rot_dir_esq( no* k1 );
int calc_alt_retira(no *T);
int FB(no *T);
void imprime_aux(no *a, int andar);
void imprime(no *a);

#endif // TAAVL_H_INCLUDED
