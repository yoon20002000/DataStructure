#include "Queue11.h"

#include <iostream>
#include <ostream>

Queue11::Queue11(size_t inCapacity) : queue(nullptr), capacity(inCapacity + 1), front(0), back(0)
{
    queue = new int[capacity];
}

Queue11::~Queue11()
{
    delete[] queue;
}

Queue11::Queue11(const Queue11& other) : queue(nullptr), capacity(other.capacity), front(other.front), back(other.back)
{
    queue = new int[capacity];
    
    for (size_t i = 0 ; i < other.capacity; i++)
    {
        queue[i] = other.queue[i];
    }
}

Queue11& Queue11::operator=(const Queue11& other)
{
    if (this != &other)
    {
        delete[] queue;

        queue = new int[capacity];
    
        for (size_t i = 0 ; i < other.capacity; i++)
        {
            queue[i] = other.queue[i];
        }
    }
    return *this;
}

Queue11::Queue11(Queue11&& other) noexcept : queue(other.queue), capacity(other.capacity), front(other.front), back(other.back)
{
    other.queue = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.back = 0;
}

Queue11& Queue11::operator=(Queue11&& other) noexcept
{
    if (this != &other)
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

void Queue11::enqueue(int value)
{
    if (isFull())
    {
        std::cout << "Queue is full." << '\n';
        return;
    }
    
    back = (back + 1) % capacity;
    queue[back] = value;
}

std::optional<int> Queue11::dequeue()
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    int returnValue = queue[front];
    front = (front + 1) % capacity;
    return returnValue;
}

std::optional<int> Queue11::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    return queue[front];
}

bool Queue11::isEmpty() const
{
    return front == back;
}

bool Queue11::isFull() const
{
    return (back + 1) % capacity == front;
}
