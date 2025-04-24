#include "Queue09.h"

#include <iostream>

Queue09::Queue09(int inCapacity) : queue(nullptr), capacity(inCapacity + 1), front(0), back(0)
{
    queue = new int[capacity];
}

Queue09::~Queue09()
{
    delete[] queue;
}

Queue09::Queue09(const Queue09& other) : queue(new int[other.capacity]), capacity(other.capacity), front(other.front), back(other.back)
{
    std::copy_n(other.queue, other.capacity, queue);
}

Queue09& Queue09::operator=(const Queue09& other)
{
    if (&other != this)
    {
        delete[] queue;
        queue = new int[other.capacity];
        std::copy_n(other.queue, other.capacity, queue);
    }
    return *this;
}

Queue09::Queue09(Queue09&& other) noexcept : queue(other.queue), capacity(other.capacity), front(other.front), back(other.back)
{
    other.queue = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.back = 0;
}

Queue09& Queue09::operator=(Queue09&& other) noexcept
{
    if (&other != this)
    {
        delete[] queue;

        queue = other.queue;
        capacity = other.capacity;
        front = other.front;
        back = other.back;

        other.queue = nullptr;
        other.capacity = 0;
        other.front = 0;
        other.back = 0;
    }
    return *this;
}

void Queue09::enqueue(int value)
{
    if (isFull())
    {
        std::cout << "Queue is Full\n";
        return;
    }

    back = (back + 1) % capacity;
    queue[back] = value;
}

int Queue09::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is Empty\n";
        return -1;
    }
    int returnValue = queue[front];
    front = (front + 1) % capacity;

    return returnValue;
}

int Queue09::peek() const
{
    if (isEmpty())
    {
        std::cout << "Queue is Empty\n";
        return -1;
    }
    return queue[front];
}

bool Queue09::isEmpty() const
{
    return front == back;
}

bool Queue09::isFull() const
{
    return (back + 1) % capacity == front;
}

int Queue09::getSize() const
{
    return (back - front + capacity) % capacity;
}
