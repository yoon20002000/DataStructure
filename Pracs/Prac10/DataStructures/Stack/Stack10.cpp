#include "Stack10.h"

#include <iostream>

Stack10::Stack10(int inCapacity) : arr(nullptr), size(0), capacity(inCapacity)
{
    arr = new int[capacity];
}

Stack10::~Stack10()
{
    delete[] arr;
}

Stack10::Stack10(const Stack10& other) : arr(nullptr), size(other.size), capacity(other.capacity)
{
    arr = new int[capacity];

    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

Stack10& Stack10::operator=(const Stack10& other)
{
    if (&other != this)
    {
        delete[] arr;
        capacity = other.capacity;
        size = other.size;

        arr = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }

    return *this;
}

Stack10::Stack10(Stack10&& other) noexcept : arr(other.arr), size(other.size), capacity(other.capacity)
{
    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Stack10& Stack10::operator=(Stack10&& other) noexcept
{
    if (&other != this)
    {
        delete[] arr;

        arr = other.arr;
        size = other.size;
        capacity = other.capacity;

        other.arr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    return *this;
}

void Stack10::push(int value)
{
    if (isFull())
    {
        std::cout << "Stack Overflow" << '\n';

        int newCapacity = static_cast<int>(capacity * 1.5f);
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }
        reserve(newCapacity);
    }

    arr[size++] = value;
}

void Stack10::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack Underflow" << '\n';
        return;
    }
    --size;
}

std::optional<int> Stack10::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }
    return arr[size - 1];
}

bool Stack10::isEmpty() const
{
    return size == 0;
}

bool Stack10::isFull() const
{
    return size == capacity;
}

void Stack10::reserve(int inCapacity)
{
    if (inCapacity <= capacity)
    {
        return;
    }
    capacity = inCapacity;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}
