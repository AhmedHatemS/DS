#include "ArrayBasedList.h"

void CreateList(List *L)
{
    L->Size = 0;
}
int ListEmpty(List *L)
{
    return L->Size == 0;
}
int ListFull(List *L)
{
    return L->Size == MAX;
}
int ListSize(List *L)
{
    return L->Size;
}
void InsertListElement(List *L, EntryType item, int pos)
{
    for (int i = L->Size-1; i>pos-1; i--)
    {
        L->Entry[i+1] = L->Entry[i];
    }
    L->Entry[pos] = item;
    L->Size++;
}
void DeleteListElement(List *L, EntryType *item, int pos)
{
    *item = L->Entry[pos];
    for (int i = pos; i < L->Size; i++)
    {
        L->Entry[i] = L->Entry[i+1];
    }
    L->Size--;
}
void MergeTwoLists(List *First, List *Second, List *InMerge)
{
    EntryType temp;
    int n = 2*ListSize(First); //Size of InMerge.

    CreateList(InMerge);

    for (int i=0; i<n; i++)
    {
        if (ListSize(First))
        {
            DeleteListElement(First, &temp, 0);
            InsertListElement(InMerge, temp, ListSize(InMerge));
        }
        if (ListSize(Second))
        {
            DeleteListElement(Second, &temp, 0);
            InsertListElement(InMerge, temp, ListSize(InMerge));
        }
    }
}
void ClearList(List *L)
{
    L->Size = 0;
}
