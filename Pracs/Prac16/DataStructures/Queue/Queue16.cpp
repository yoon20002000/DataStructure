#include "Queue16.h"

#include <cstdio>

Queue16::Queue16() : front(0), back(0)
{
    queue = new int[MAX_CAPACITY];
}

Queue16::~Queue16()
{
    delete[] queue;
}

void Queue16::enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }

    queue[back] = value;
    back = (back + 1) % MAX_CAPACITY;
}

std::optional<int> Queue16::dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return std::nullopt;
    }
    int returnVal = queue[front];
    front = (front + 1) % MAX_CAPACITY;
    return returnVal;
}
