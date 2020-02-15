#include <stdlib.h>
#include <stdio.h>
#include "busca-em-vetor.h"

int main(){
    int valores[10] = {2,3,5,7,11,13,23,29,31,37};
    printf("Posicao do 2: %d\n", buscaLinear(valores, 10, 2));
    printf("Posicao do 37: %d\n", buscaOrdenada(valores, 10, 37));
    printf("Posicao do 53: %d\n", buscaBinaria(valores, 10, 53));
    return 0;
}