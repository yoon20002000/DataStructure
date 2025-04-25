#include "Queue10.h"

#include <iostream>

Queue10::Queue10(int inCapacity) : arr(nullptr), front(0), back(0), capacity(inCapacity + 1)
{
    arr = new int[capacity];
}

Queue10::~Queue10()
{
    delete[] arr;
}

Queue10::Queue10(const Queue10& other) : arr(nullptr), front(other.front), back(other.back), capacity(other.capacity)
{
    arr = new int[capacity];

    for (int i = 0; i < capacity; i++)
    {
        arr[i] = other.arr[i];
    }
}

Queue10& Queue10::operator=(const Queue10& other)
{
    if (&other != this)
    {
        delete[] arr;

        front = other.front;
        back = other.back;
        capacity = other.capacity;
        arr = new int[capacity];

        for (int i = 0; i < capacity; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

Queue10::Queue10(Queue10&& other) noexcept : arr(other.arr), front(other.front), back(other.back),
                                             capacity(other.capacity)
{
    other.arr = nullptr;
    other.front = 0;
    other.back = 0;
    other.capacity = 0;
}

Queue10& Queue10::operator=(Queue10&& other) noexcept
{
    if (&other != this)
    {
        delete[] arr;
        arr = other.arr;
        front = other.front;
        back = other.back;
        capacity = other.capacity;

        other.arr = nullptr;
        other.front = 0;
        other.back = 0;
        other.capacity = 0;
    }
    return *this;
}

void Queue10::enqueue(int value)
{
    if (isFull())
    {
        std::cout << "Queue is full\n";
        return;
    }
    arr[back] = value;
    back = (back + 1) % capacity;
}

std::optional<int> Queue10::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return std::nullopt;
    }
    int returnValue = arr[front];
    front = (front + 1) % capacity;

    return returnValue;
}

std::optional<int> Queue10::peek() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
        return std::nullopt;
    }
    return arr[front];
}

bool Queue10::isEmpty() const
{
    return front == back;
}

bool Queue10::isFull() const
{
    return (back + 1) % capacity == front;
}
