#ifndef LINKEDBASEDSTACK_H_INCLUDED
#define LINKEDBASEDSTACK_H_INCLUDED

typedef int EntryType;
typedef struct node
{
    EntryType Info;
    struct node *Next;
} Node;
typedef Node *Stack;

void CreateStack(Stack *ps);
void PushElement(EntryType e, Stack *ps);
void PopElement(EntryType *e, Stack *ps);
void DestroyStack(Stack *ps);
EntryType ReturnFirst(Stack *ps);
EntryType ReturnLast(Stack *ps);
int StackSize(Stack *ps);
int StackFull(Stack *ps);
int StackEmpty(Stack *ps);

#endif // LINKEDBASEDSTACK_H_INCLUDED
