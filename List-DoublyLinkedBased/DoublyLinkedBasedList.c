#include <stdlib.h>
#include "DoublyLinkedBasedList.h"

void CreateList(List *L)
{
	*L = NULL;
}

int ListEmpty(List *L)
{
	return (*L == NULL);
}

int ListFull(List *L)
{
	return 0;
}

int ListSize(List *L)
{
    Node *q;
    if (*L == NULL)
        return 0;
    else
        q = *L;
    int Size=1;
    while (q->Next)
    {
        q=q->Next;
        Size++;
    }
    return Size;
}
void InsertListElement(List *L, EntryType item, int pos)
{
   Node *p = (Node *)malloc(sizeof(Node));
   p->Info.Data = item;
   /*if (*L == NULL) // done in the next if in its if
   {
       *L = p;
       p->Next = NULL;
       p->Prev = NULL;
   }
   else*/ if (pos == 0)
   {
       p->Next = *L;
       if (*L) // if (*L != NULL)
            (*L)->Prev = p;
       *L = p;
       p->Prev = NULL;
   }
   else
    {
        Node *q;    int i;
        for (q=*L, i=0; i<pos-1; i++)
            q=q->Next;
        p->Next = q->Next;
        if (q->Next)
            q->Next->Prev = p;
        p->Prev = q;
        q->Next = p;
    }
}
void DeleteListElement(List *L, EntryType *item, int pos)
{
    int i;
    if ((*L)->Prev == NULL && (*L)->Next == NULL)
    {
        *item = (*L)->Info.Data;
        free(L);
        *L = NULL;
    }
    else if (pos == 0)
    {
        *item = (*L)->Info.Data;
        *L = (*L)->Next;
        free((*L)->Prev);
        (*L)->Prev = NULL;
    }
    else
    {
        Node *q;
        for (q=*L, i=0; i<pos; i++)
            q=q->Next;
        *item = q->Info.Data;
        q->Prev->Next = q->Next;
        if (q->Next)
            q->Next->Prev = q->Prev;
        free(q);
    }
}
void ClearList(List *L)
{
    Node *q;
    while(*L)
    {
        q=*L;
        *L=(*L)->Next;
        free(q);
    }
}
