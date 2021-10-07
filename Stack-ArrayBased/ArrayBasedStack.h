#ifndef ARRAYBASEDSTACK_H_INCLUDED
#define ARRAYBASEDSTACK_H_INCLUDED

#define MAX 5

typedef char EntryType;
typedef struct Stack
{
    int Top;
    EntryType Entry[MAX];
}Stack;

void CreateStack(Stack *ps);
void PushElement(EntryType e, Stack *ps);
void PopElement(EntryType *e, Stack *ps);
void DestroyStack(Stack *ps);
EntryType ReturnFirst(Stack *ps);
EntryType ReturnLast(Stack *ps);
EntryType StackTop(Stack *ps);
int StackSize(Stack *ps);
int StackFull(Stack *ps);
int StackEmpty(Stack *ps);

#endif // ARRAYBASEDSTACK_H_INCLUDED
