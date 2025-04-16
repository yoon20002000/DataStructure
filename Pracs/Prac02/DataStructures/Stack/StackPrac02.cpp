#include "StackPrac02.h"

#include <algorithm>
#include <codecvt>
#include <iostream>

StackPrac02::StackPrac02() : stack(nullptr), size(0), capacity(0)
{
    
}

StackPrac02::StackPrac02(int capacity)
{
    reserve(capacity);
}

StackPrac02::~StackPrac02()
{
    delete[] stack;
}

StackPrac02::StackPrac02(const StackPrac02& other): stack(nullptr)
{
    reserve(other.capacity);
    std::copy_n(other.stack, other.size, stack);
}

StackPrac02& StackPrac02::operator=(const StackPrac02& other)
{
    delete[] stack;

    size = other.size;
    reserve(other.capacity);
    std::copy_n(other.stack, other.size, stack);

    return *this;
}

StackPrac02::StackPrac02(StackPrac02&& other)
{
    capacity = other.capacity;
    size = other.size;
    stack = other.stack;
    
    other.capacity = 0;
    other.size = 0;
    other.stack = nullptr;
}

StackPrac02& StackPrac02::operator=(StackPrac02&& other)
{
    delete[] stack;
    
    capacity = other.capacity;
    size = other.size;
    stack = other.stack;
    
    other.capacity = 0;
    other.size = 0;
    other.stack = nullptr;
    return *this;
}

void StackPrac02::push(int value)
{
    if (capacity == size)
    {
        int newCapacity = capacity + (capacity >> 1);
        if (newCapacity == capacity)
        {
            newCapacity++;
        }
        reserve(newCapacity);
    }

    stack[size] = value;
    size++;
}

int StackPrac02::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    int returnValue = stack[size-1];
    size--;
    return returnValue;
}

int StackPrac02::top() const
{
    if (isEmpty())
    {
        return -1;
    }

    return stack[size-1];
}

bool StackPrac02::isEmpty() const
{
    return size == 0;
}

void StackPrac02::reserve(int newCapacity)
{
    if (newCapacity <= capacity)
    {
        return;
    }

    capacity = newCapacity;
    int* newStack = new int[newCapacity];
    std::copy_n(stack, size, newStack);
    delete[] stack;
    stack = newStack;
}

int StackPrac02::getCapacity() const
{
    return capacity;
}

int StackPrac02::getSize() const
{
    return size;
}

void StackPrac02::printStack() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << stack[i] << " ";
    }
}
