#include "Stack16.h"

Stack16::Stack16()
{
    capacity = 2;
    stack = new int[capacity];
}

Stack16::~Stack16()
{
    delete[] stack;
}

Stack16::Stack16(const Stack16& other)
{
    capacity = other.capacity;
    // 메모리 절약을 위해
    stack = new int[other.size];
    size = other.size;
    std::ranges::copy(other.stack, other.stack + other.size, stack);
}

Stack16& Stack16::operator=(const Stack16& other)
{
    if (this != &other)
    {
        delete[] stack;
        
        capacity = other.capacity;
        // 메모리 절약을 위해
        stack = new int[other.size];
        size = other.size;
        std::ranges::copy(other.stack, other.stack + other.size, stack);
    }

    return *this;
}

Stack16::Stack16(Stack16&& other) noexcept
{
    capacity = other.capacity;
    size = other.size;
    stack = other.stack;

    other.capacity = 0;
    other.size = 0;
    other.stack = nullptr;
}

Stack16& Stack16::operator=(Stack16&& other) noexcept
{
    if (this != &other)
    {
        delete[] stack;
        capacity = other.capacity;
        size = other.size;
        stack = other.stack;

        other.capacity = 0;
        other.size = 0;
        other.stack = nullptr;
    }

    return *this;
}

void Stack16::push(int value)
{
    if (capacity <= size)
    {
        resize(capacity * 2);
    }

    stack[size++] = value;
}

void Stack16::pop()
{
    if (isEmpty())
    {
        return;
    }
    --size;
}

std::optional<int> Stack16::top() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    return stack[size - 1];
}

void Stack16::resize(int newCapacity)
{
    if (newCapacity <= capacity)
    {
        return;
    }
    
    int* newData = new int[newCapacity];
    std::ranges::copy(stack, stack + size, newData);
    delete[] stack;
    capacity = newCapacity;
    stack = newData;
}
