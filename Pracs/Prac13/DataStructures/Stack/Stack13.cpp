#include "Stack13.h"

#include <iostream>
#include <ostream>

Stack13::Stack13(size_t inCapacity) : stack(nullptr), size(0), capacity(inCapacity)
{
    stack = new int[capacity];
}

Stack13::~Stack13()
{
    delete [] stack;
}

Stack13::Stack13(const Stack13& other) : stack(nullptr), size(other.size), capacity(other.capacity)
{
    stack = new int[capacity];
    for (size_t i = 0; i < size; i++)
    {
        stack[i] = other.stack[i];
    }
}

Stack13& Stack13::operator=(const Stack13& other)
{
    if (&other != this)
    {
        delete[] stack;
        stack = new int[capacity];
        for (size_t i = 0; i < size; i++)
        {
            stack[i] = other.stack[i];
        }
        capacity = other.capacity;
        size = other.size;
    }

    return *this;
}

Stack13::Stack13(Stack13&& other) noexcept : stack(other.stack), size(other.size), capacity(other.capacity)
{
    other.stack = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Stack13& Stack13::operator=(Stack13&& other) noexcept
{
    if (&other != this)
    {
        delete[] stack;

        stack = other.stack;
        size = other.size;
        capacity = other.capacity;

        other.stack = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    return *this;
}

void Stack13::push(int value)
{
    if (capacity == size)
    {
        size_t newCapacity = capacity * 1.5f;
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }
        reserve(newCapacity);
    }
    stack[size] = value;
    size++;
}

void Stack13::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack underflow" << '\n';
        return;
    }
    --size;
}

std::optional<int> Stack13::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }
    return stack[size - 1];
}

void Stack13::reserve(size_t newCapacity)
{
    if (capacity >= newCapacity)
    {
        return;
    }

    int* newStack = new int[newCapacity];
    for (size_t i = 0; i < size; ++i)
    {
        newStack[i] = stack[i];
    }
    delete[] stack;
    stack = newStack;
    
    capacity = newCapacity;
}
