#include "busca-em-vetor.h"

int buscaLinear(int* vetor, int tamanho, int elemento){
    if((!vetor) || tamanho <= 0) return -1;
    for(int i =0; i < tamanho; i++){
        if(vetor[i] == elemento) return i;
    }
    return -1;
}
int buscaOrdenada(int* vetor, int tamanho, int elemento){
    if((!vetor) || tamanho <= 0) return -1;
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] == elemento)
            return i;
        else
            if(vetor[i] > elemento) return -1;
    }
    return -1;
}
int buscaBinaria(int* vetor, int tamanho, int elemento){
    if((!vetor) || tamanho <= 0) return -1;
    int inicio, meio, final;
    inicio = 0;
    final = tamanho - 1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if(vetor[meio] > elemento)
            final = meio - 1;
        else
            if(vetor[meio] < elemento)
                inicio = meio + 1;
            else return meio;
    }
    return -1;
}