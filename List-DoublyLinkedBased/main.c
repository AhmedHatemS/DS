#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedBasedList.h"

int main()
{
    List L;
    EntryType x;
    CreateList(&L);
    int i=0; char c='A';
    while(i<58)
    {
        if ((c>='A' && c<='Z') || (c>='a' && c<='z'))
        {
            InsertListElement(&L, c, ListSize(&L));
            printf("%2d ", ListSize(&L));
        }
        i++;
        c++;
    }
    printf("\n");
    while(!ListEmpty(&L))
    {
        DeleteListElement(&L, &x, 0);
        printf("%c ", x);
    }
    return 0;
}
