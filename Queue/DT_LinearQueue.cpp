#include "DT_LinearQueue.h"

#include <iostream>
#include <ostream>

DT_LinearQueue::DT_LinearQueue(int inCapacity) : front (0), rear(0), capacity(inCapacity)
{
    data = new int[capacity];
}

DT_LinearQueue::~DT_LinearQueue()
{
    delete[] data;
}

void DT_LinearQueue::enQueue(int inData)
{
    if (isFull())
    {
        std::cout << "Queue is full" << '\n';
        return;
    }
    data[rear] = inData;
    rear++;
}

int DT_LinearQueue::deQueue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << '\n';
        return -1;
    }
    int returnValue = data[front];
    front++;
    return returnValue;
}

bool DT_LinearQueue::isEmpty()
{
    return front == rear;
}

bool DT_LinearQueue::isFull()
{
    return rear == capacity;
}
