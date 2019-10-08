#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"
#include "exercicios.h"
#include "TAAVL.h"
int main(){
    TAB *a = cria_ab(8, NULL, NULL);
    a = insere_abb(3, a);
    a = insere_abb(10, a);
    a = insere_abb(1, a);
    a = insere_abb(6, a);
    a = insere_abb(14, a);
    a = insere_abb(4, a);
    a = insere_abb(7, a);
    a = insere_abb(13, a);
    imprime_ab(a);

    printf("\n");
    printf("\n");
    TAB *c = cria_ab(7, NULL, NULL);
    int nointerno = ni(a);
    printf("Nos internos: %d", nointerno);
    /*
    printf("\n");
    int *v, j;
    j = 0;
    v = mn(a, 7);
    while(v[j]){
        printf("[%i] = %i\n", j, v[j]);
        j++;
    }
    free(v);
    printf("\n");
    printf("\n");

    TAB* b = retira_impares(a);
    imprime_ab(b);
    int altura_b = altura(b);
    printf("Altura da arvore: %d", altura_b);
    */
    return 0;
}
