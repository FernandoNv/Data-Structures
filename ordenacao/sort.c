#include "sort.h"
#include <math.h>

void bubbleSort(int* vetor, int tamanho){
    if(!vetor || tamanho <= 0) return;
    int i,aux;
    for(i = 0; i < tamanho-1; i++){
        if(vetor[i] > vetor[i+1]){
            aux = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = aux;
        }
    }
    bubbleSort(vetor, tamanho-1);
}

void insertionSort(int* vetor, int tamanho){
    if(!vetor || tamanho <= 0) return;
    int i,j,menor, aux;
    for(i = 0; i < tamanho; i++){
        menor = i;
        for(j = i; j < tamanho; j++){
            if(vetor[menor] > vetor[j]) menor = j;
        }
        if(vetor[i] != vetor[menor]){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

void selectionSort(int* vetor, int tamanho){
    if(!vetor || tamanho <= 0) return;
    int i, j, aux;
    for(i = 1; i < tamanho; i++){
        aux = vetor[i];
        for(j = i; (j > 0) && vetor[j-1] > aux; j--) vetor[j] = vetor[j-1];
        vetor[j] = aux;
    }
}

void merge(int* vetor, int inicio, int meio, int fim){
    int* temp, p1,p2,tamanho,i,j,k, fim1 = 0, fim2 = 0;
    
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    //criar vetor dinamicamente
    temp = (int*) malloc(sizeof(int)*tamanho);

    if(temp){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(vetor[p1] < vetor[p2])
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];
                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;
            }else{
                if(!fim1)
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++)
            vetor[k] = temp[j];
    }
    free(temp);
}

void mergeSort(int* vetor, int inicio, int fim){
    int meio;
    //ainda há elemento para ser ordenado
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

int particiona(int* vetor, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = vetor[inicio];
    while(esq < dir){
        while(vetor[esq] <= pivo && esq <= fim) esq++;
        while(vetor[dir] > pivo && dir>= 0) dir--;
        if(esq < dir){
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;

    return dir;
}

void quickSort(int* vetor, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}