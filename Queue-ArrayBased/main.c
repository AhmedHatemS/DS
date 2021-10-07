#include <stdio.h>
#include <stdlib.h>
#include "ArrayBasedQueue.h"

int main()
{
    Queue q;
    CreateQueue(&q);
    EntryType item;
    while(!QueueFull(&q))
    {
        printf("Enter ");
        scanf("%d", &item);
        EnqueueElement(item, &q);
    }

    printf("\nFirst is: %d", DisplayFirst(&q));
    printf("\nLast is: %d", DisplayLast(&q));
    printf("\nSize is: %d", QueueSize(&q));
    printf("\nMaximum %d\n", ReturnMax(&q));

    while(!QueueEmpty(&q))
    {
        DequeueElement(&item, &q);
        printf("%d ", item);
    }
    printf("\nMaximum %d\n", ReturnMax(&q));
    QueueDestroy(&q);
    return 0;
}
