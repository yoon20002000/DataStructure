#include "Stack11.h"

Stack11::Stack11(int inCapacity) : arr(nullptr), capacity(inCapacity), size(0)
{
    arr = new int[inCapacity];
}

Stack11::~Stack11()
{
    delete[] arr;
}

Stack11::Stack11(const Stack11& other) : arr(nullptr), capacity(other.capacity), size(other.size)
{
    arr = new int[other.capacity];
    
    for (int i = 0 ; i < other.size; i++)
    {
        arr[i] = other.arr[i];
    }
}

Stack11& Stack11::operator=(const Stack11& other)
{
    if (&other != this)
    {
        delete[] arr;
        
        arr = new int[other.capacity];
        capacity = other.capacity;
        size = other.size;
        
        for (int i = 0 ; i < other.size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

Stack11::Stack11(Stack11&& other) noexcept : arr(other.arr), capacity(other.capacity), size(other.size)
{
    other.arr = nullptr;
    other.capacity = 0;
    other.size = 0;
}

Stack11& Stack11::operator=(Stack11&& other) noexcept
{
    if (&other != this)
    {
        delete[] arr;

        arr = other.arr;
        capacity = other.capacity;
        size = other.size;
        
        other.arr = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

void Stack11::push(int value)
{
    if (capacity == size)
    {
        int newCapacity = static_cast<int>(capacity * 1.5);
        if (newCapacity == capacity)
        {
            ++newCapacity;
        }
        reserve(newCapacity);
    }

    arr[size++] = value;
}

void Stack11::pop()
{
    if (isEmpty())
    {
        return;
    }
    --size;
}

std::optional<int> Stack11::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    return arr[size - 1];
}

bool Stack11::isEmpty() const
{
    return size == 0;
}

void Stack11::reserve(int inCapacity)
{
    if (capacity >= inCapacity)
    {
        return;
    }

    capacity = inCapacity;
    int* newArr = new int[capacity];

    for (int i = 0 ; i < size;++i)
    {
        newArr[i] = arr[i];
    }
    
    delete[] arr;
    arr = newArr;
}
