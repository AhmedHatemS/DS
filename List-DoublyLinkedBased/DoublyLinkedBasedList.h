#ifndef DOUBLYLINKEDBASEDLIST_H_INCLUDED
#define DOUBLYLINKEDBASEDLIST_H_INCLUDED

typedef char EntryType;
typedef struct {
    //int Key; //I don't need it.
    EntryType Data;
}Element;
typedef struct node
{
    Element Info;
    struct node *Prev;
    struct node *Next;
}Node;
typedef Node *List;

void CreateList(List *L);
int ListEmpty(List *L);
int ListFull(List *L);
int ListSize(List *L);
void InsertListElement(List *L, EntryType item, int pos);
void DeleteListElement(List *L, EntryType *item, int pos);
//void PrintList(List L);
//void PrintListReversed(List L);
void ClearList(List *L);

#endif // DOUBLYLINKEDBASEDLIST_H_INCLUDED
