#include "Stack09.h"

#include <iostream>

Stack09::Stack09(int inCapacity) : stack(nullptr), capacity(0), size(0)
{
    reserve(inCapacity);
}

Stack09::~Stack09()
{
    delete [] stack;
}

Stack09::Stack09(const Stack09& other) : stack(nullptr), capacity(0), size(0)
{
    reserve(other.capacity);
    std::copy_n(other.stack, other.size, stack);
    size = other.size;
}

Stack09& Stack09::operator=(const Stack09& other)
{
    if (&other != this)
    {
        delete [] stack;

        reserve(other.capacity);
        std::copy_n(other.stack, other.size, stack);
        size = other.size;
    }
    return *this;
}

Stack09::Stack09(Stack09&& other) noexcept : stack(other.stack), capacity(other.capacity), size(other.size)
{
    other.stack = nullptr;
    other.capacity = 0;
    other.size = 0;
}

Stack09& Stack09::operator=(Stack09&& other) noexcept
{
    if (&other != this)
    {
        delete[] stack;

        stack = other.stack;
        capacity = other.capacity;
        size = other.size;

        other.stack = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

void Stack09::push(int value)
{
    if (isFull())
    {
        int newCapacity = static_cast<int>(capacity * 1.5);
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }

        reserve(newCapacity);
    }

    stack[size] = value;
    ++size;
}

void Stack09::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty." << '\n';
        return;
    }
    --size;
}

int Stack09::peek() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty." << '\n';
        return -1;
    }
    return stack[size - 1];
}

void Stack09::reserve(int inCapacity)
{
    if (capacity >= inCapacity)
    {
        return;
    }
    capacity = inCapacity;
    int* newStack = new int[capacity];

    for (int i = 0; i < size; ++i)
    {
        newStack[i] = stack[i];
    }

    delete[] stack;
    stack = newStack;
}

bool Stack09::isEmpty() const
{
    return size == 0;
}

bool Stack09::isFull() const
{
    return capacity == size;
}
