#include "Queue07.h"

#include <iostream>

Queue07::Queue07(int size) : capacity(size), front(0), rear(0)
{
    data = new int[capacity];
}

Queue07::~Queue07()
{
    delete [] data;
}

void Queue07::enqueue(int value)
{
    if (isFull())
    {
        std::cout << "Queue is full\n";
        return;
    }
    data[rear] = value;
    rear = (rear + 1) % capacity;
}

int Queue07::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }
    int returnValue = data[front];
    front = (front+1) % capacity;
    return returnValue;
}

int Queue07::peak() const
{
    if (isEmpty())
    {
        return -1;
    }
    return data[front];
}

int Queue07::size() const
{
    return (rear - front + capacity) % capacity;
}

bool Queue07::isEmpty() const
{
    return rear == front;
}

bool Queue07::isFull() const
{
    return (rear + 1) % capacity == front;
}
