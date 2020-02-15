#include"queue.h"

Queue* qCreate(){
    return NULL;
}

Queue* qPush(Queue *q, Type info){
    if(!q){
        Queue *aux = malloc(sizeof(Queue));
        aux->info = info;
        aux->next = NULL;

        return aux;
    }
    Queue *aux1 = q;
    while(aux1->next){
        aux1 = aux1->next;
    }
    Queue *aux = malloc(sizeof(Queue));
    aux->info = info;
    aux->next = NULL;

    aux1->next = aux;

    return q;
}

int qIsEmpty(Queue *q){
    if(!q) return 1;
    return 0;
}
Queue* qRemove(Queue *q, Type info){
    if(!q) return q;
    if(q->info == info){
        Queue *aux = q;
        aux = aux->next;
        free(q);

        return aux;
    }
    Queue *q1 = q;
    Queue *q2 = q->next;
    if(q2->info == info){
        q1->next = q2->next;
        free(q2);

        return q1;
    }

    while(q2){
        if(q2->info == info){
            q1->next = q2->next;
            free(q2);

            return q;
        }
        q2 = q2->next;
        q1 = q1->next;
    }

    return NULL;
}
Queue* qPop(Queue *q){
    if(!q) return q;
    Queue *aux = q;
    aux = aux->next;
    free(q);
    return aux;
}
Type qPeek(Queue *q){
    return q->info;
}
Queue* qDestroy(Queue *q){
    if(!q) return q;
    q = qPop(q);
    return qDestroy(q);
}
void qPrint(Queue *q){
    if(!q) return;
    printf("%d ", q->info);
    qPrint(q->next);
}
