#include <stdio.h>
#include <stdlib.h>
#include "LinkedBasedListWithSize.h"

int main()
{
    List X,Y,Z;
    EntryType show;

    CreateList(&X);
    CreateList(&Y);

    int i=0; char c='A';
    while(i<58)
    {
        if (c>='A' && c<='Z')
        {
            InsertListElement(&X, c, ListSize(&X));
            printf("%2d ", ListSize(&X));
        }
        else if (c>='a' && c<='z')
        {
            InsertListElement(&Y, c, ListSize(&Y));
            printf("%2d ", ListSize(&Y));
        }
        i++;
        c++;
    }
    printf("\n");
    MergeTwoLists(&X, &Y, &Z);
    while(!ListEmpty(&Z))
    {
        DeleteListElement(&Z, &show, 0);
        printf("%2c ", show);
    }
   /*
   printf("\n");
    while(!ListEmpty(&L))
    {
        DeleteListElement(&L, &x, 0);
        printf("%c ", x);
    }
    */
    return 0;
}
