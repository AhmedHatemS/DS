#include <stdio.h>
#include <stdlib.h>
#include "LinkedBasedStack.h"

int main()
{
    Stack s;
    CreateStack(&s);
    EntryType e;

    for (int i=0 ; i<5 ; i++)
    {
        scanf("%d", &e);
        PushElement(e, &s);
    }

    printf("The first Now is : %d\n", ReturnFirst(&s));
    printf("The last Now is : %d\n", ReturnLast(&s));
    printf("The Size Now is : %d\n", StackSize(&s));

    PopElement(&e, &s);
    printf("The Poped Element is : %d\n", e );

    PopElement(&e, &s);
    printf("The Poped Element is : %d\n", e );

    printf("The Size Before Clear is : %d\n", StackSize(&s));

    DestroyStack(&s);
    printf("The Size After Clear is : %d\n", StackSize(&s));

    //pop(&s, &e);
    //printf("The Poped Element is : %d\n" , e );

    return 0;
}
