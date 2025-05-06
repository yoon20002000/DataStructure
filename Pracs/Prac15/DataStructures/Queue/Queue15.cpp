#include "Queue15.h"

#include <iostream>
#include <ostream>

Queue15::Queue15(size_t inCapacity) : queue(nullptr), front(0), back(0), capacity(inCapacity + 1)
{
    queue = new int[capacity];
}

Queue15::~Queue15()
{
    delete [] queue;
}

Queue15::Queue15(const Queue15& other) : capacity(other.capacity), front(other.front), back(other.back)
{
    queue = new int[capacity];
    std::copy_n(other.queue, other.capacity, queue);
}

Queue15& Queue15::operator=(const Queue15& other)
{
    if (&other != this)
    {
        delete [] queue;
        queue = new int[other.capacity];
        std::copy_n(other.queue, other.capacity, queue);
        capacity = other.capacity;
        front = other.front;
        back = other.back;
    }
    
    return *this;
}

Queue15::Queue15(Queue15&& other) noexcept : queue(other.queue), front(other.front), back(other.back), capacity(other.capacity)
{
    other.queue = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.back = 0;
}

Queue15& Queue15::operator=(Queue15&& other) noexcept
{
    if (&other != this)
    {
        delete [] queue;

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

void Queue15::enqueue(int value)
{
    if (isFull())
    {
        std::cout << "Queue is full." << '\n';
        return;
    }
    back = (back + 1) % capacity;
    queue[back] = value;
}

std::optional<int> Queue15::dequeue()
{
    if (isEmpty())
    {
        return std::nullopt;
    }
    int returnValue = queue[front];
    front = (front + 1) % capacity;
    return returnValue; 
}

std::optional<int> Queue15::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }
    return  queue[front];
}

bool Queue15::isEmpty() const
{
    return front == back;
}

bool Queue15::isFull() const
{
    return (back + 1)% capacity == front;
}
