#include "Stack05.h"

Stack05::Stack05() : data(nullptr), size(0), capacity(0)
{
    reserve(2);
}

Stack05::Stack05(int newCapacity)
{
    reserve(newCapacity);
}

Stack05::~Stack05()
{
    deleteStack();
}

Stack05::Stack05(const Stack05& other): data(nullptr), size(other.size), capacity(0)
{
    reserve(other.capacity);

    copyStack(other);
}

Stack05& Stack05::operator=(const Stack05& other) 
{
    if (&other != this)
    {
        deleteStack();
    
        reserve(other.capacity);

        copyStack(other);
    }

    return *this;
}

Stack05::Stack05(Stack05&& other) noexcept
{
    data = other.data;
    capacity = other.capacity;
    size = other.size;
    
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

Stack05& Stack05::operator=(Stack05&& other) noexcept
{
    if (&other != this)
    {
        deleteStack();

        data = other.data;
        capacity = other.capacity;
        size = other.size;
    
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

void Stack05::push(int value)
{
    if (capacity == size)
    {
        int newCapacity = capacity * 1.5f;
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }
        reserve(newCapacity);
    }

    data[size] = value;
    size++;
}

void Stack05::pop()
{
    if (isEmpty())
    {
        return;
    }
    size--;
}

void Stack05::clear()
{
    size = 0;
}

int Stack05::top() const
{
    if (data == nullptr || isEmpty())
    {
        return -1;
    }
    
    return data[size - 1];
}

bool Stack05::isEmpty() const
{
    return size == 0;
}

void Stack05::reserve(int newCapacity)
{
    if (capacity >= newCapacity)
    {
        return;
    }

    capacity = newCapacity;

    int* newData = new int[capacity];
    if (data != nullptr)
    {
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
    }
    
    data = newData;
}

void Stack05::copyStack(const Stack05& other)
{
    for (int i = 0 ; i < other.size ; i++)
    {
        data[i] = other.data[i];
    }    
}

void Stack05::deleteStack()
{
    delete[] data;
    data = nullptr;
}
