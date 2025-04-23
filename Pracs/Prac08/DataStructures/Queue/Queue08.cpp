#include "Queue08.h"

#include <iostream>
#include <ostream>

Queue08::Queue08(int inCapacity) : arr(nullptr), front(0), back(0), capacity(inCapacity + 1)
{
    arr = new int[capacity];
}

Queue08::~Queue08()
{
    delete [] arr;
}

Queue08::Queue08(const Queue08& other) : arr(nullptr), front(other.front), back(other.back), capacity(other.capacity)
{
    arr = new int[capacity];
    for (int i = 0; i < capacity; ++i)
    {
        arr[i] = other.arr[i];
    }
}

Queue08& Queue08::operator=(const Queue08& other)
{
    if (&other != this)
    {
        delete [] arr;

        front = other.front;
        back = other.back;
        capacity = other.capacity;
        
        arr = new int[capacity];
        for (int i = 0; i < capacity; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

Queue08::Queue08(Queue08&& other) noexcept : arr(other.arr), front(other.front), back(other.back),
                                             capacity(other.capacity)
{
    other.arr = nullptr;
    other.front = 0;
    other.back = 0;
    other.capacity = 0;
}

Queue08& Queue08::operator=(Queue08&& other) noexcept
{
    if (&other != this)
    {
        delete [] arr;

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

void Queue08::enqueue(int value)
{
    if (isFull())
    {
        std::cout << "Queue is full." << '\n';
        return;
    }
    back = (back + 1) % capacity;
    arr[back] = value;
}

int Queue08::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty." << '\n';
        return -1;
    }
    int returnValue = arr[front];
    front = (front + 1) % capacity;

    return returnValue;
}

int Queue08::peek() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty." << '\n';
        return -1;
    }

    return arr[front];
}

bool Queue08::isEmpty() const
{
    return front == back;
}

bool Queue08::isFull() const
{
    return (back + 1) % capacity == front;
}

int Queue08::getSize() const
{
    return (back - front + capacity) % capacity;
}
