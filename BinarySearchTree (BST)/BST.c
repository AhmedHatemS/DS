#include <stdlib.h>
#include "BST.h"
void CreateTree(Tree *t)
{
    *t = NULL;
}
int TreeEmpty(Tree *t)
{
    return *t == NULL;
}
int TreeFull(Tree *t)
{
    return 0;
}
void InOrder(Tree t, void(*pvisit)(Entry))
{
    if(t)
    {
        InOrder(t->Left, pvisit);
        (*pvisit)(t->Info);
        InOrder(t->Right, pvisit);
    }
}
void PreOrder(Tree t, void(*pvisit)(Entry))
{
    if(t)
    {
        (*pvisit)(t->Info);
        PreOrder(t->Left, pvisit);
        PreOrder(t->Right, pvisit);
    }
}
void PostOrder(Tree t, void(*pvisit)(Entry))
{
    if(t)
    {
        PostOrder(t->Left, pvisit);
        PostOrder(t->Right, pvisit);
        (*pvisit)(t->Info);
    }
}
int TreeSize(Tree t)
{
    if (!t)
        return 0;
    return (1 + TreeSize(t->Left) + TreeSize(t->Right));
}
int TreeHeight(Tree t)
{
    if (!t)
        return 0;
    int a=TreeHeight(t->Left);
    int b=TreeHeight(t->Right);
    return (a>b)? 1+a : 1+b;
}
void PrintLevel(Tree *t, int level, void(*pvisit)(Entry))
{
    if (t != NULL && level == 0)
    {
        (*pvisit)((*t)->Info);
    }
    else if (t != NULL)
    {
        PrintLevel((*t)->Left, level - 1, pvisit);
        PrintLevel((*t)->Right, level - 1, pvisit);
    }
}
void ClearTree(Tree *t)
{
    if (*t)
    {
        ClearTree(&(*t)->Left);
        ClearTree(&(*t)->Right);
        free(*t);
        *t=NULL;
    }
}
void Insert(Tree *t,EntryType item)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->Info=item;
    p->Left=NULL;
    p->Right=NULL;
    if (!(*t))
        *t= p;
    else
    {
        Node *pre,*cur;
        cur=*t;
        while(cur)
        {
            pre=cur;
            if(item<cur->Info)
                cur=cur->Left;
            else
                cur=cur->Right;
        }
        if(item <pre->Info)
            pre->Left=p;
        else
            pre->Right=p;
    }
}
int Delete(Tree *t,EntryType k)
{
    int found=0;
    Node *q=*t;
    Node *r=NULL;
    while(q && !(found=(k==q->Info)))
    {
        r=q;
        if(k<q->Info)
            q=q->Left;
        else
            q=q->Right;
    }
    if (found)
    {
        if(!r)//Case of deleting the root
            DeleteNode(t);
        else if((k< r->Info))
            DeleteNode(&r->Left);
        else
            DeleteNode(&r->Right);
    }
    return found;
}
void DeleteNode(Tree *pt)
{
    Node *q=*pt;
    if(!(q)->Left)
        *pt=(q)->Right;
    else if(!(q)->Right)
        *pt=(q)->Left;
    else
    {
        //third case
        q=(q)->Left;
        Node *r=NULL;
        while(q->Right)
        {
            r=q;
            q=q->Right;
        }
        (*pt)->Info=q->Info;
        if(r)
            r->Right=q->Left;
        else
            (*pt)->Left=q->Left;
    }
    free(q);
}
