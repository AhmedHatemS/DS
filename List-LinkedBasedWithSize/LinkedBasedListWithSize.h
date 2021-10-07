#ifndef LINKEDBASEDLISTWITHSIZE_H_INCLUDED
#define LINKEDBASEDLISTWITHSIZE_H_INCLUDED

typedef char EntryType;
typedef struct node{
    EntryType info;
    struct node *next;
}Node;
typedef struct
{
    Node *head;
    int Size;
}List;

void CreateList(List *L);
int ListEmpty(List *L);
int ListFull(List *L);
int ListSize(List *L);
void InsertListElement(List *L, EntryType item, int pos);
void DeleteListElement(List *L, EntryType *item, int pos);
void MergeTwoLists(List *First, List *Second, List *InMerge);
//void PrintList(List L);
//void PrintListReversed(List L);
void ClearList(List *L);

#endif // LINKEDLISTWITHSIZE_H_INCLUDED
