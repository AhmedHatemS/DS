#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef int EntryType;
typedef struct node{
    EntryType Info;
    struct node *Left;
    struct node *Right;
}Node;
typedef Node *Tree;

void CreateTree(Tree *t);
int TreeEmpty(Tree *t);
int TreeFull(Tree *t);
void InOrder(Tree t, void(*pvisit)(Entry));
void PreOrder(Tree t, void(*pvisit)(Entry));
void PostOrder(Tree t, void(*pvisit)(Entry));
int TreeSize(Tree t);
int TreeHeight(Tree t);
void PrintLevel(Tree *t, int level, void(*pvisit)(Entry));
void ClearTree(Tree *t);
void Insert(Tree *t,EntryType item);
int Delete(Tree *t,EntryType k);


#endif // BST_H_INCLUDED
