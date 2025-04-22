#include "Stack07.h"

Stack07::Stack07() : stack(nullptr), capacity(0), size(0)
{
    reserve(1);
}

Stack07::~Stack07()
{
    delete[] stack;
}

Stack07::Stack07(const Stack07& other) : stack(nullptr), capacity(0), size(0)
{
    reserve(other.capacity);

    for (int i = 0 ; i < other.size; ++i)
    {
        stack[i] = other.stack[i];
    }
    size = other.size;
}

Stack07& Stack07::operator=(const Stack07& other)
{
    if (&other != this)
    {
        delete[] stack;
        size = 0;
        reserve(other.capacity);

        for (int i = 0 ; i < other.size; ++i)
        {
            stack[i] = other.stack[i];
        }
        size = other.size;
    }
    return *this;
}

Stack07::Stack07(Stack07&& other) noexcept : stack(nullptr), capacity(0), size(0)
{
    stack = other.stack;
    capacity = other.capacity;
    size = other.size;

    other.stack = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Stack07& Stack07::operator=(Stack07&& other) noexcept
{
    if (&other != this)
    {
        stack = other.stack;
        capacity = other.capacity;
        size = other.size;

        other.stack = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    
    return *this;
}

void Stack07::reserve(int newCapacity)
{
    if (capacity >= newCapacity)
    {
        return;
    }
    capacity = newCapacity;
    int* newStack = new int[capacity];
    for (int i = 0 ; i < size; ++i)
    {
        newStack[i] = stack[i];
    }
    delete[] stack;
    stack = newStack;
}

void Stack07::push(int data)
{
    if (capacity == size)
    {
        int newCapacity = static_cast<int>(capacity * 1.5f);
        reserve(newCapacity);
    }
    stack[size] = data;
    size++;
}

void Stack07::pop()
{
    if (isEmpty())
    {
        return;
    }
    --size;
}

int Stack07::peek() const
{
    if (isEmpty())
    {
        return -1;
    }
    return stack[size - 1];
}

bool Stack07::isEmpty() const
{
    return size == 0;
}
