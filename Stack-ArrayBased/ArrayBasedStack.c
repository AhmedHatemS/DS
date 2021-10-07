#include <stdio.h>
#include <stdlib.h>
#include "ArrayBasedStack.h"

void CreateStack(Stack *ps)
{
   ps->Top=0;
}
void PushElement(EntryType e, Stack *ps)
{
	 ps->Entry[ps->Top++]=e;
}
void PopElement(EntryType *e, Stack *ps)
{
    *e = ps->Entry[--ps->Top];
}
void DestroyStack(Stack *ps)
{
    ps->Top=0;
}
EntryType ReturnFirst(Stack *ps)
{
    return ps->Entry[0];
}
EntryType ReturnLast(Stack *ps)
{
    return ps->Entry[ps->Top-1];
}
EntryType StackTop(Stack *ps){
	return ps->Entry[ps->Top-1];
}
int StackSize(Stack *ps)
{
    return (ps->Top);
}
int StackFull(Stack *ps){
   return (ps->Top==MAX);
}
int StackEmpty(Stack *ps){
   return (ps->Top==0);
}
