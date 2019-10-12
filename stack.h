#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int Type;
typedef struct Stack{
    Type info;
    struct Stack* next;
}Stack;

Stack* sCreate();
Stack* sPush(Stack *s, Type info);
int sIsEmpty(Stack *s);
Stack* sRemove(Stack *s, Type info);
Stack* sPop(Stack *s);
Type sPeek(Stack *s);
Stack* sDestroy(Stack *s);
void sPrint(Stack *s);
#endif // STACK_H_INCLUDED
