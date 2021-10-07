#include <stdio.h>
#include <stdlib.h>
#include "ArrayBasedStack.h"

int main()
{
    Stack s;
    EntryType x;
    CreateStack(&s);
    while(!StackFull(&s))
    {
        scanf("%c", &x);
        PushElement(x, &s);
    }
    printf("\n\n");
    while(!StackEmpty(&s))
    {
        PopElement(&x, &s);
        printf("%c ", x);

    }
    printf("\nsize: %d\n", StackSize(&s));
    return 0;
}
