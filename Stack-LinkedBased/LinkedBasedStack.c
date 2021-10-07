#include <stdlib.h>
#include "LinkedBasedStack.h"

void CreateStack(Stack *ps)
{
    *ps = NULL;
}
void PushElement(EntryType e, Stack *ps)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->Info = e;
    if (*ps == NULL)
    {
        p->Next = *ps;
        *ps = p;
    }
    else
    {
        Node *q;
        q = *ps;
        while (q->Next)
            q=q->Next;
        p->Next = q->Next;
        q->Next = p;
    }
}
void PopElement(EntryType *e, Stack *ps)
{
    Node *q, *tmp;
    if ((*ps)->Next == NULL)
    {
        *e = (*ps)->Info;
        tmp = *ps;
        *ps = (*ps)->Next;
        free(tmp);
    }
    else
    {
        q = *ps;
        while (q->Next->Next)
            q=q->Next;
        *e =q->Next->Info;
        tmp=q->Next;
        q->Next=tmp->Next;
        free(tmp);
    }
}
void DestroyStack(Stack *ps)
{
    Node *q;
    while(*ps)
    {
        q=*ps;
        *ps=(*ps)->Next;
        free(q);
    }
}
EntryType ReturnFirst(Stack *ps)
{
    return (*ps)->Info;
}
EntryType ReturnLast(Stack *ps)
{
    Node *q;
    q = *ps;
    while (q->Next)
        q = q->Next;
    return q->Info;
}
int StackSize(Stack *ps)
{
    Node *q;
    if (*ps == NULL)
        return 0;
    else
        q = *ps;
    int Size=1;
    while (q->Next)
    {
        q=q->Next;
        Size++;
    }
    return Size;
}
int StackFull(Stack *ps)
{
    return 0;
}
int StackEmpty(Stack *ps)
{
    return (*ps == NULL); ;
}
