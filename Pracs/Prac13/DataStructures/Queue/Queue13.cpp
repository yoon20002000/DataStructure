#include "Queue13.h"

Queue13::Queue13(size_t inCapacity) : queue(nullptr), capacity(inCapacity + 1), front(0), back(0)
{
    queue = new int[capacity];
}

Queue13::~Queue13()
{
    delete[] queue;
}

Queue13::Queue13(const Queue13& other) : queue(nullptr), capacity(other.capacity), front(other.front), back(other.back)
{
    queue = new int[capacity];
}

Queue13& Queue13::operator=(const Queue13& other)
{
    if (&other != this)
    {
        delete[] queue;
        queue = new int[other.capacity];
        std::copy_n(other.queue, other.capacity, queue);
        capacity = other.capacity;
        front = other.front;
        back = other.back;
    }
    return *this;
}

Queue13::Queue13(Queue13&& other) noexcept : queue(other.queue), capacity(other.capacity), front(other.front), back(other.back)
{
    other.queue = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.back = 0;
}

Queue13& Queue13::operator=(Queue13&& other) noexcept
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

void Queue13::enqueue(int value)
{
    if (isFull())
    {
        size_t newCapacity = capacity * 1.5;
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }
        reserve(newCapacity);
    }

    back = (back + 1) % capacity;
    queue[back] = value;
}

std::optional<int> Queue13::dequeue()
{
    if (isEmpty())
    {
        return std::nullopt;
    }
    int returnValue = queue[front];
    front = (front+1) % capacity;

    return returnValue;
}

std::optional<int> Queue13::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    return queue[front];
}

void Queue13::reserve(size_t inCapacity)
{
    if (capacity >= inCapacity + 1)
    {
        return;
    }
    int* newQueue = new int[inCapacity + 1];

    std::copy_n(queue, capacity, newQueue);
    delete[] queue;
    queue = newQueue;
    
    capacity = inCapacity + 1;
}