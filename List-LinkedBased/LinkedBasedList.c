#include <stdlib.h>
#include "LinkedBasedList.h"


void CreateList(List *L)
{
	*L = NULL;
}

int ListEmpty(List L)
{
	return (L == NULL);
}

int ListFull(List L)
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
    while (q->next)
    {
        q=q->next;
        Size++;
    }
    return Size;
}
void InsertListElement(List *L, EntryType item, int pos)
{
   Node *p = (Node *)malloc(sizeof(Node));
   p->info = item;
   if (pos == 0)
   {
       p->next = *L;
       *L = p;
   }
   else
    {
        Node *q;    int i;
        for (q=*L, i=0; i<pos-1; i++)
            q=q->next;
        p->next = q->next;
        q->next = p;
    }
}
void DeleteListElement(List *L, EntryType *item, int pos)
{
    int i;  Node *q, *tmp;
    if (pos == 0)
    {
        *item = (*L)->info;
        tmp = *L;
        *L = (*L)->next;
        free(tmp);
    }
    else
    {
        for (q=*L, i=0; i<pos-1; i++)
            q=q->next;
        *item=q->next->info;
        tmp=q->next;
        q->next=tmp->next;
        free(tmp);
    }
}

void MergeTwoLists(List *First, List *Second, List *InMerge)
{
    *InMerge = *First;
    *First = (*First)->next;
    (*InMerge)->next = *Second;
    *Second = (*Second)->next;
    Node *q;
    q = (*InMerge)->next;
    while(*First || *Second)
    {
        if (*First)
        {
            q->next = *First;
            *First = (*First)->next;
            q = q->next;
        }
        if (*Second)
        {
            q->next = *Second;
            *Second = (*Second)->next;
            q = q->next;
        }
    }
    q->next = NULL;
}

void ClearList(List *L)
{
    Node *q;
    while(*L)
    {
        q=*L;
        *L=(*L)->next;
        free(q);
    }
}
