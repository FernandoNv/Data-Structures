#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"
#include "exercicios.h"

int main(){
    TAB *b = cria_ab(7, NULL, NULL);
    TAB *c = cria_ab(1, NULL, NULL);
    TAB *d = cria_ab(11, NULL, NULL);
    TAB *e = cria_ab(12, NULL, NULL);
    TAB *f = cria_ab(75, d, e);
    TAB *a = cria_ab(10, b, c);
    TAB *g = cria_ab(100, a, f);
    TAB *h = cria_ab(125, NULL, NULL);
    TAB *i = cria_ab(14, h, NULL);
    TAB *j = cria_ab(311, g, i);

    //TAB *k = cria_ab(4, NULL, NULL);
    //TAB *l = cria_ab(3, k, NULL);
    //TAB *m = cria_ab(2, NULL, NULL);
    //TAB *n = cria_ab(1, m, l);


    int qtd_nos = ni(j);
    printf("Quantidade de nos em J: %i\n", qtd_nos);
    //printf("Print n\n");
    //colore(n);
    printf("\n");
    imprime_ab(j);
    /*
    printf("Print g\n");
    imprime_ab(g);
    printf("\n");
    printf("\n");

    TAB *copia_g = copia(g);
    printf("Print copia g\n");
    imprime_ab(copia_g);
    printf("\n");
    printf("\n");

    TAB *espelha_i = espelho(g);

    imprime_ab(espelha_i);
    printf("\n");
    printf("Print j \n");
    imprime_ab(j);
    printf("\n");
    printf("\n");
    */
    //TAB *maior = maiorElemento(n);
    //printf("%i\n", maior->info);

    //int resp = igual(g, j);
    //printf("%i", resp);
    return 0;
}
