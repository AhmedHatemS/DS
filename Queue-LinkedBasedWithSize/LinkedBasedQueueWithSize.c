#include "LinkedBasedQueueWithSize.h"
#include <stdlib.h>

void CreateQueue(Queue *q)
{
    q->Front = NULL;
    q->Rear = NULL;
    q->Size = 0;
}
void EnqueueElement(EntryType item, Queue *q)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->Info = item;
    if (q->Front == NULL)
    {
        p->Next = q->Rear;
        q->Front = p;
        q->Rear = p;
    }
    else
    {
        p->Next = q->Rear->Next;
        q->Rear->Next = p;
        q->Rear = q->Rear->Next;

    }
    q->Size++;
}
void DequeueElement(EntryType *item, Queue *q)
{
    *item = q->Front->Info;
    Node *temp;
    temp = q->Front;
    q->Front = q->Front->Next;
    free(temp);
    if (q->Front == NULL)
        q->Rear = NULL;
    q->Size--;
}
EntryType DisplayFirst(Queue *q)
{
    return q->Front->Info;
}
EntryType DisplayLast(Queue *q)
{
    return q->Rear->Info;
}
int QueueFull(Queue *q)
{
    return 0;
}
int QueueEmpty(Queue *q)
{
    return q->Front == NULL;
}
int QueueSize(Queue *q)
{
    return q->Size;
}

void QueueDestroy(Queue *q)
{
    Node *temp;
    while (q->Front)
    {
        temp = q->Front;
        q->Front = q->Front->Next;
        free(temp);
    }
    q->Rear = q->Front;
}
EntryType ReturnMax(Queue *q)
{
    ///pre:
    /*if (q->Size == 0)
        return 0;*/
    ///InCode:
    EntryType maximum;
    Node *temp;
    temp = q->Front->Next;
    maximum = q->Front->Info;
    for (int i=1; i<q->Size; i++)
    {
        if (temp->Info > maximum)
        {
            maximum = temp->Info;
        }
        temp = temp->Next;
    }
    return maximum;
}
