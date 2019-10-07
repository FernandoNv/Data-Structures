#include "exercicios.h"
int ehMaior(int a, int b){
    if(a > b){
        return 1;
    }else if(a < b){
        return -1;
    }else{
        return 0;
    }
}

TAB* copia(TAB *a){
    if(!a) return a;
    TAB *aux = (TAB*) malloc(sizeof(TAB));
    aux->info = a->info;
    aux->esq = copia(a->esq);
    aux->dir = copia(a->dir);
    return aux;
}

TAB* espelho(TAB *a){
    if(!a) return a;
    TAB *aux = (TAB*) malloc(sizeof(TAB));
    aux->info = a->info;
    aux->esq = espelho(a->dir);
    aux->dir = espelho(a->esq);
    return aux;
}

TAB* maiorElemento(TAB *a){
    if(!a) return a;
    TAB *maior = a;
    TAB *aux1 = maiorElemento(a->esq);
    if(aux1 != NULL && aux1->info > maior->info){
        maior = aux1;
    }

    TAB *aux2 = maiorElemento(a->dir);
    if(aux2 != NULL && aux2->info > maior->info){
        maior = aux2;
    }
    return maior;
}

int igual(TAB* a1, TAB* a2){
    if((!a1) && (!a2)) return 1;
    if(a1->info == a2->info){
        int resp1 = igual(a1->esq, a2->esq);
        int resp2 = igual(a1->dir, a2->dir);

        if((resp1) && (resp2)){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}

void colore(TAB *arv){
    int cor = 1;
    arv->cor = cor;
    coloreFilho(arv->esq, !cor);
    coloreFilho(arv->dir, !cor);
    return;
}

void coloreFilho(TAB *arv, int cor){
    if(!arv) return;
    arv->cor = cor;
    coloreFilho(arv->esq, !cor);
    coloreFilho(arv->dir, !cor);

    return;
}

int ni(TAB *a){
    if(!a){
        return 0;
    }else{
        int cont = 1;
        cont = cont + ni(a->esq);
        cont = cont + ni(a->dir);
        return cont;
    }
}

TABB* maior(TAB *a){
    if(!a) return a;
    if(a->dir) return maior(a->dir);
    return a;
}

TAB* retira_impares(TAB *a){
    if(!a) return a;
    a->esq = retira_impares(a->esq);
    a->dir = retira_impares(a->dir);
    if(a->info % 2){
        return retira_abb(a->info, a);
    }
    return a;
}

int* mn(TAB *a, int n){
    if(!a) return NULL;
    int tamanho_vetor = ni(a) + 1;
    int *v, i = 0;
    v = (int *) malloc(tamanho_vetor * sizeof(int));
    for(int j = 0; j<tamanho_vetor; j++){
        v[j] = NULL;
    }
    mnaux(a,n,v,i);
    return v;
}

int mnaux(TAB *a,int n,int *v,int i){
    if(!a) return i;
    i = mnaux(a->esq, n , v, i);
    if(a->info < n){
        v[i] = a->info;
        i++;
    }
    i = mnaux(a->dir, n , v, i);
    return i;
}

int altura(TAB *a){
    if(!a) return -1;
    return altura_max(altura(a->esq), altura(a->dir)) + 1;
}

int altura_max(int a, int b){
    if((a<0) || (b<0)){
        if((a<0) && (b<0)){
            return 0;
        }
        if(a < 0) return b;
        return a;
    }
    if(a > b){
        return a;
    }
    return b;
}
