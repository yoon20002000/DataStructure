#include "DT_Stack.h"

#include <iostream>

DT_Stack::DT_Stack() : size(0), capacity(0), data(nullptr)
{
    reserve(1);
}

DT_Stack::DT_Stack(int capacity) : size(0)
{
    reserve(capacity);
}

DT_Stack::DT_Stack(const DT_Stack& other)
{
    reserve(other.capacity);
    size = other.size;
    std::copy(other.data, other.data + size, data);
}

DT_Stack::DT_Stack(DT_Stack&& other) noexcept
{
    size = other.size;
    capacity = other.capacity;
    data = other.data;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

DT_Stack::~DT_Stack()
{
    delete[] data;
}

DT_Stack& DT_Stack::operator=(const DT_Stack& other)
{
    if (this != &other)
    {
        delete[] data;
        
        reserve(other.capacity);
        size = other.size;
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

DT_Stack& DT_Stack::operator=(DT_Stack&& other) noexcept
{
    if (other.data != nullptr)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

void DT_Stack::push(int inData)
{
    if (capacity == size)
    {
        int newCapacity = static_cast<int>(capacity * 1.5f);
        if (newCapacity == capacity)
        {
            newCapacity++;
        }

        reserve(newCapacity);
    }

    data[size] = inData;
    size += 1;
}

int DT_Stack::pop()
{
    if (size > 0)
    {
        int returnValue = data[size - 1];
        size -= 1;
        return returnValue;
    }
    else
    {
        return -1;
    }
}

int DT_Stack::peek() const
{
    if (size > 0)
    {
        return data[size - 1];
    }
    else
    {
        return -1;
    }
}

void DT_Stack::reserve(int newCapacity)
{
    if (capacity > newCapacity)
    {
        return;
    }
    capacity = newCapacity;

    int* newData = new int[newCapacity];

    for (int i = 0; i < size; ++i)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}

void DT_Stack::printStack() const
{
    for (int i = size - 1; i >= 0; --i)
    {
        std::cout << data[i] << std::endl;
    }
}
