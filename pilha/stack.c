#include"stack.h"

Stack* sCreate(){
    return NULL;
}
Stack* sPush(Stack *s, Type info){
    Stack *aux = malloc(sizeof(Stack));
    aux->info = info;

    if(!s){
        aux->next = NULL;
    }
    aux->next = s;

    return aux;
}
int sIsEmpty(Stack *s){
    if(!s) return 0;
}
Stack* sRemove(Stack *s, Type info){
    if(!s) return s;
    if(s->info == info){
        Stack *aux = s;
        s = s->next;
        free(aux);

        return s;
    }

    Stack *s1 = s;
    Stack *s2 = s->next;
    if(s2->info == info){
        s1->next = s2->next;
        free(s2);

        return s1;
    }

    while(s2){
        if(s2->info == info){
            s1->next = s2->next;
            free(s2);

            return s;
        }
        s2 = s2->next;
        s1 = s1->next;
    }

    return NULL;
}
Stack* sPop(Stack *s){
    if(!s) return s;
    Stack *aux = s;
    s = s->next;
    free(aux);
    return s;
}
Type sPeek(Stack *s){
    return s->info;
}
Stack* sDestroy(Stack *s){
    if(!s) return s;
    s = sPop(s);
    return sDestroy(s);
}
void sPrint(Stack *s){
    if(!s) return;
    printf("%d ", s->info);
    return sPrint(s->next);
}
