#include "Stack15.h"

Stack15::Stack15(size_t inCapacity) : stack(nullptr), capacity(inCapacity), size(0)
{
    stack = new int[inCapacity];
}

Stack15::~Stack15()
{
    delete[] stack;
}

Stack15::Stack15(const Stack15& other) : stack(nullptr), capacity(other.capacity), size(other.size)
{
    stack = new int [capacity];
    std::copy_n(other.stack, size, stack);
}

Stack15& Stack15::operator=(const Stack15& other)
{
    if (&other != this)
    {
        delete[] stack;
        stack = new int [other.capacity];
        capacity = other.capacity;
        size = other.size;
        std::copy_n(other.stack, size, stack);
    }
    return *this;
}

Stack15::Stack15(Stack15&& other) noexcept : stack(other.stack), capacity(other.capacity), size(other.size)
{
    other.stack = nullptr;
    other.capacity = 0;
    other.size = 0;
}

Stack15& Stack15::operator=(Stack15&& other) noexcept
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

void Stack15::push(int value)
{
    if (isFull())
    {
        size_t newCapacity = static_cast<size_t>(capacity * 1.5f);
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }
        reserve(newCapacity);
    }

    stack[size++] = value;
}

void Stack15::pop()
{
    if (isEmpty())
    {
        return;
    }
    --size;
}

std::optional<int> Stack15::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    return  stack[size-1];
}

bool Stack15::isEmpty() const
{
    return size == 0;
}

bool Stack15::isFull() const
{
    return size == capacity;
}

void Stack15::reserve(size_t inCapacity)
{
    if (capacity >= inCapacity)
    {
        return;
    }
    int* newStack = new int[inCapacity];
    std::copy_n(stack,  size, newStack);

    delete [] stack;
    stack = newStack;
    capacity = inCapacity;
}
