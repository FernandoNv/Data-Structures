#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"
#include "exercicios.h"

int main(){
    TAB *a = cria_ab(8, NULL, NULL);
    TAB *b = insere_abb(3, a);
    TAB *c = insere_abb(10, b);
    TAB *d = insere_abb(1, c);
    TAB *e = insere_abb(6, d);
    TAB *f = insere_abb(14, e);
    TAB *g = insere_abb(4, f);
    TAB *h = insere_abb(7, g);
    TAB *i = insere_abb(13, h);
    imprime_ab(g);
    //TAB* g_sem_impares = retira_impares(g);

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    //imprime_ab(g_sem_impares);

    int *v, j;
    j = 0;
    v = mn(i, 20);
    while(v[j]){
        printf("[%i] = %i\n", j, v[j]);
        j++;
    }
    free(v);
    return 0;
}
