#include "Queue14.h"

Queue14::Queue14(size_t inCapacity) : queue(nullptr), capacity(inCapacity + 1),front(0), back(0)
{
    if (inCapacity == 0)
    {
        capacity = 2;
    }

    queue = new int[capacity];
}

Queue14::~Queue14()
{
    delete [] queue;
}

Queue14::Queue14(const Queue14& other) : queue(nullptr), capacity(other.capacity), front(other.front), back(other.back)
{
    if (capacity == 0)
    {
        capacity = 2;
    }

    queue = new int[capacity];
    std::copy_n(other.queue, capacity, queue);
}

Queue14& Queue14::operator=(const Queue14& other)
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

Queue14::Queue14(Queue14&& other) noexcept : queue(other.queue), capacity(other.capacity), front(other.front), back(other.back)
{
    other.queue = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.back = 0;
}

Queue14& Queue14::operator=(Queue14&& other) noexcept
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

void Queue14::enqueue(int value)
{
    if (isFull())
    {
        size_t newCapacity = capacity * 1.5f;
        reserve(newCapacity);
    }
    back = (back + 1) % capacity;
    queue[back] = value;
}

std::optional<int> Queue14::dequeue()
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    int returnValue = queue[front];
    front = (front + 1) % capacity;

    return returnValue;
}

std::optional<int> Queue14::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }
    return queue[front];
}


void Queue14::reserve(size_t inCapacity)
{
    if (capacity >= inCapacity)
    {
        return;
    }

    int* newQueue = new int[inCapacity];
    std::copy_n(queue, capacity, newQueue);
    delete[] queue;
    queue = newQueue;
    capacity = inCapacity;
}
