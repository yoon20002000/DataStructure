#include "DT_CycleQueue.h"

#include <iostream>
#include <ostream>

DT_CycleQueue::DT_CycleQueue(): front(0), rear(0)
{
    
}

DT_CycleQueue::~DT_CycleQueue()
{
    
}

void DT_CycleQueue::enQueue(int inData)
{
    if (isFull())
    {
        std::cout << "Queue is full" << '\n';
        return;
    }
    else
    {
        data[rear] = inData;
        rear = (rear + 1) % MAX_QUEUE_SIZE;
    }
}

int DT_CycleQueue::deQueue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << '\n';
        return -1;
    }
    else
    {
        int returnValue = data[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        return returnValue;
    }
}

bool DT_CycleQueue::isEmpty() const
{
    return front == rear;
}

bool DT_CycleQueue::isFull() const
{
    return (rear +1) % MAX_QUEUE_SIZE == front;
}

void DT_CycleQueue::printQueue() const
{
    if (isEmpty())
    {
        return;
    }

    for (int i = front; i != rear; i = (i + 1) % MAX_QUEUE_SIZE)
    {
        std::cout << data[i] << " ";
    }
}
