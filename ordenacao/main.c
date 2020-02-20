#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

int main(){
    int valores[10] = {17,7,15,22,1,12,2,47,13,3};
    for(int i = 0; i < 10; i++) printf("%d ", valores[i]);
    printf("\n");
    quickSort(valores, 0, 9);
    for(int i = 0; i < 10; i++) printf("%d ", valores[i]);
    printf("\n");
    return 0;
}