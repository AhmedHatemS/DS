#ifndef LINKEDBASEDQUEUE_H_INCLUDED
#define LINKEDBASEDQUEUE_H_INCLUDED

typedef int EntryType;
typedef struct node
{
    EntryType Info;
    struct node *Next;
} Node;
typedef struct q
{
    Node *Front;
    Node *Rear;
} Queue; //points to front

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

#endif // LINKEDBASEDQUEUE_H_INCLUDED
