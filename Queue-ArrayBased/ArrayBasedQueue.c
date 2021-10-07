#include "ArrayBasedQueue.h"

void CreateQueue(Queue *q)
{
    q->Front=0;
    q->Rear = -1;
    q->Size = 0;
}
void EnqueueElement(EntryType item, Queue *q)
{
    q->Rear = (q->Rear+1)%MAX;
    q->Entry[q->Rear] = item;
    q->Size++;
}
void DequeueElement(EntryType *item, Queue *q)
{
    *item = q->Entry[q->Front];
    q->Front = (q->Front+1)%MAX;
    q->Size--;
}
EntryType DisplayFirst(Queue *q)
{
    return q->Entry[q->Front];
}
EntryType DisplayLast(Queue *q)
{
    return q->Entry[q->Rear];
}
int QueueFull(Queue *q)
{
    return (q->Size==MAX);
}
int QueueEmpty(Queue *q)
{
    return (q->Size==0);
}
int QueueSize(Queue *q)
{
    return (q->Size);
}
void QueueDestroy(Queue *q)
{
    q->Front=0;
    q->Rear = -1;
    q->Size = 0;
}
EntryType ReturnMax(Queue *q)
{
    ///pre:
    /*if (q->Size == 0)
        return 0;*/
    ///InCode:
    EntryType maximum, temp;
    maximum = q->Entry[q->Front];
    for (int i=0; i<q->Size; i++)
    {
        ///Dequeue
        temp = q->Entry[q->Front];
        q->Front = (q->Front+1)%MAX;
        ///Enqueue
        q->Rear = (q->Rear+1)%MAX;
        q->Entry[q->Rear] = temp;
        ///Check
        if (temp>maximum)
            maximum = temp;
    }
    return maximum;
}
