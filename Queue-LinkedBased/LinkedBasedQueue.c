#include "LinkedBasedQueue.h"
#include <stdlib.h>

void CreateQueue(Queue *q)
{
    q->Front = NULL;
    q->Rear = NULL;
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
    if (q->Front == NULL)
        return 0;
    int Size = 1;
    Node *temp;
    temp = q->Front;
    while (temp->Next)
    {
        temp = temp->Next;
        Size++;
    }
    return Size;
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
    /*if (q->Front == NULL)
        return 0;*/
    ///InCode:
    EntryType maximum;
    Node *temp;
    temp = q->Front->Next;
    maximum = q->Front->Info;
    while (temp->Next)
    {
        if (temp->Info > maximum)
        {
            maximum = temp->Info;
        }
        temp = temp->Next;
    }
    return maximum;
}
