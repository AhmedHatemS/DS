#ifndef ARRAYBASEDQUEUE_H_INCLUDED
#define ARRAYBASEDQUEUE_H_INCLUDED

#define MAX 5

typedef int EntryType;
typedef struct Queue{
    int Front;
    int Rear;
    int Size;
    EntryType Entry[MAX];
}Queue;

void CreateQueue(Queue *q);
void EnqueueElement(EntryType item, Queue *q);
void DequeueElement(EntryType *item, Queue *q);
EntryType DisplayFirst(Queue *q);
EntryType DisplayLast(Queue *q);
int QueueFull(Queue *q);
int QueueEmpty(Queue *q);
int QueueSize(Queue *q);
void QueueDestroy(Queue *q);
EntryType ReturnMax(Queue *q);

#endif // ARRAYBASEDQUEUE_H_INCLUDED
