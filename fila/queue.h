#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int Type;
typedef struct Queue{
    Type info;
    struct Queue *next;
} Queue;

Queue* qCreate();
Queue* qPush(Queue *q, Type info);
int qIsEmpty(Queue *q);
Queue* qRemove(Queue *q, Type info);
Queue* qPop(Queue *q);
Type qPeek(Queue *q);
Queue* qDestroy(Queue *q);
void qPrint(Queue *q);
#endif // QUEUE_H_INCLUDED
