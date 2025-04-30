#include "Stack14.h"

Stack14::Stack14(size_t inCapacity) : stack(nullptr), capacity(inCapacity), size(0)
{
    if (capacity == 0)
    {
        capacity = 1;
    }
    stack = new int[capacity];
}

Stack14::~Stack14()
{
    delete[] stack;
}

Stack14::Stack14(const Stack14& other) : stack(nullptr), capacity(other.capacity), size(other.size)
{
    stack = new int[other.capacity];

    std::copy_n(other.stack, other.size, stack);
}

Stack14& Stack14::operator=(const Stack14& other)
{
    if (&other != this)
    {
        delete[] stack;

        stack = new int[other.capacity];

        std::copy_n(other.stack, other.size, stack);
        capacity = other.capacity;
        size = other.size;
    }

    return *this;
}

Stack14::Stack14(Stack14&& other) noexcept : stack(other.stack), capacity(other.capacity), size(other.size)
{
    other.stack = nullptr;
    other.capacity = 0;
    other.size = 0;
}

Stack14& Stack14::operator=(Stack14&& other) noexcept
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

void Stack14::push(int value)
{
    if (isFull())
    {
        size_t newCapacity = capacity * 1.5f;
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }
        reserve(newCapacity);
    }

    stack[size] = value;
    ++size;
}

void Stack14::pop()
{
    if (isEmpty())
    {
        return;
    }
    --size;
}

std::optional<int> Stack14::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    return stack[size - 1];
}

bool Stack14::isEmpty() const
{
    return size == 0;
}

bool Stack14::isFull() const
{
    return capacity == size;
}

void Stack14::reserve(size_t inCapacity)
{
    if (capacity >= inCapacity)
    {
        return;
    }
    int* newStack = new int[inCapacity];

    std::copy_n(stack, size, newStack);
    delete[] stack;

    capacity = inCapacity;
    stack = newStack;
}
