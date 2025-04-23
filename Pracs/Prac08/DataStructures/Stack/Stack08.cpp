#include "Stack08.h"

#include <iostream>
#include <ostream>

Stack08::Stack08(int inCapacity) : data(nullptr), capacity(0), size(0)
{
    reserve(inCapacity);
}

Stack08::~Stack08()
{
    delete [] data;
}

Stack08::Stack08(const Stack08& other) : data(nullptr), capacity(0), size(other.size)
{
    reserve(other.capacity);
    for (int i = 0 ; i < other.size; ++i)
    {
        data[i] = other.data[i];
    }
}

Stack08& Stack08::operator=(const Stack08& other)
{
    if (&other != this)
    {
        delete [] data;
        
        reserve(other.capacity);
        for (int i = 0 ; i < other.size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Stack08::Stack08(Stack08&& other) noexcept
{
    data = other.data;
    capacity = other.capacity;
    size = other.size;

    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

Stack08& Stack08::operator=(Stack08&& other) noexcept
{
    if (&other != this)
    {
        delete [] data;
        
        data = other.data;
        capacity = other.capacity;
        size = other.size;

        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

void Stack08::push(int value)
{
    if (capacity == size)
    {
        int newCapacity = static_cast<int>(capacity * 1.5f);
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }
        
        reserve(newCapacity);
    }
    data[size++] = value;
}

void Stack08::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty." << '\n';
        return;
    }
    --size;
}

int Stack08::peek() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty." << '\n';
        return -1;
    }

    return data[size-1];
}

bool Stack08::isEmpty() const
{
    return size == 0;
}

int Stack08::getSize() const
{
    return size;
}

void Stack08::reserve(int newCapacity)
{
    if (capacity >= newCapacity)
    {
        return;
    }

    capacity = newCapacity;
    int* newData = new int[capacity];

    for (int i = 0 ; i < size; ++i)
    {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
}
