#include <stdlib.h>
#include "LinkedBasedListWithSize.h"


void CreateList(List *L)
{
	L->head = NULL;
	L->Size = 0;
}

int ListEmpty(List *L)
{
	return (L->head == NULL);
}

int ListFull(List *L)
{
	return 0;
}

int ListSize(List *L)
{
    return L->Size;
}
void InsertListElement(List *L, EntryType item, int pos)
{
   Node *p = (Node *)malloc(sizeof(Node));
   p->info = item;
   if (pos == 0)
   {
       p->next = L->head;
       L->head = p;
   }
   else
    {
        Node *q;    int i;
        for (q=L->head, i=0; i<pos-1; i++)
            q=q->next;
        p->next = q->next;
        q->next = p;
    }
    L->Size++;
}
void DeleteListElement(List *L, EntryType *item, int pos)
{
    int i;  Node *q, *tmp;
    if (pos == 0)
    {
        *item = (L->head)->info;
        tmp = L->head;
        L->head = (L->head)->next;
        free(tmp);
    }
    else
    {
        for (q=L->head, i=0; i<pos-1; i++)
            q=q->next;
        *item=q->next->info;
        tmp=q->next;
        q->next=tmp->next;
        free(tmp);
    }
    L->Size--;
}

void MergeTwoLists(List *First, List *Second, List *InMerge)
{
    InMerge->head = First->head;
    First->head = (First->head)->next;
    (InMerge->head)->next = Second->head;
    Second->head = (Second->head)->next;
    Node *q;
    q = (InMerge->head)->next;
    while(First->head || Second->head)
    {
        q->next = First->head;
        First->head = (First->head)->next;
        q->next->next = Second->head;
        Second->head = (Second->head)->next;
        q = q->next->next;
    }
    q->next = NULL;
}

void ClearList(List *L)
{
    Node *q;
    while(L->head)
    {
        q=L->head;
        L->head=(L->head)->next;
        free(q);
    }
}
