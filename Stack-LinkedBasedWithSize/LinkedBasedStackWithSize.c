#include <stdio.h>
#include <stdlib.h>
#include "LinkedBasedStackWithSize.h"

void CreateStack(Stack *ps)
{
    ps->Top = NULL ;
    ps->Size = 0 ;
}
void PushElement(EntryType e, Stack *ps)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->Info = e;
    p->Next = ps->Top;
    ps->Top = p;
    ps->Size++;
}
void PopElement(EntryType *e, Stack *ps)
{
    Node *q ;
    *e = ps->Top->Info;
    q = ps->Top ;
    ps->Top = q->Next ;
    free(q);
    ps->Size--;
}
void DestroyStack(Stack *ps)
{
    Node *q ;
    while(ps->Top)
    {
        q=ps->Top;
        ps->Top = ps->Top->Next ;
        free(q);
        ps->Size--;
    }
}
EntryType ReturnFirst(Stack *ps)
{
    Node *q;
    q = ps->Top;
    while (q->Next)
        q = q->Next;
    return q->Info;
}
EntryType ReturnLast(Stack *ps)
{
    return ps->Top->Info;
}
int StackSize(Stack *ps)
{
    return ps->Size;
}
int StackFull(Stack *ps)
{
    return 0;
}
int StackEmpty(Stack *ps)
{
    return (ps->Size == 0) ;
}
