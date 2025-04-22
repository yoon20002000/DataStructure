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

Queue07::Queue07(const Queue07& other)
{
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0 ; i < capacity ; i++)
    {
        data[i] = other.data[i];
    }
    front = other.front;
    rear = other.rear;
}

Queue07& Queue07::operator=(const Queue07& other)
{
    if (&other != this)
    {
        delete [] data;
        capacity = other.capacity;
        data = new int[capacity];
        for (int i = 0 ; i < capacity ; i++)
        {
            data[i] = other.data[i];
        }
        front = other.front;
        rear = other.rear;
    }
    return *this;
}

Queue07::Queue07(Queue07&& other) noexcept
{
    data = other.data;
    capacity = other.capacity;
    front = other.front;
    rear = other.rear;

    other.data = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.rear = 0;
}

Queue07& Queue07::operator=(Queue07&& other) noexcept
{
    if (&other != this)
    {
        delete [] data;
        data = other.data;
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;

        other.data = nullptr;
        other.capacity = 0;
        other.front = 0;
        other.rear = 0;
    }
    return *this;
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
