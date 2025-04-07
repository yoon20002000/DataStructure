#include "DT_SLLQueue.h"

DT_SLLQueue::DT_SLLQueue() : front(nullptr), rear(nullptr)
{
}

DT_SLLQueue::~DT_SLLQueue()
{
    while (front !=nullptr)
    {
        SingleLinkedListNode* next = front->next;
        delete front;
        front = next;
    }
}

void DT_SLLQueue::enqueue(int data)
{
    SingleLinkedListNode* newNode = new SingleLinkedListNode(data);
    if (rear == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;    
    }
}

int DT_SLLQueue::dequeue()
{
    if (front == nullptr)
    {
        return -1;
    }
    else
    {
        SingleLinkedListNode* nextFront = front->next;
        int data = front->data;
        delete front;
        front = nextFront;
        return data;
    }
}

int DT_SLLQueue::peek() const
{
    if (front != nullptr)
    {
        return front->data;    
    }
    else
    {
        return -1;
    }
}
