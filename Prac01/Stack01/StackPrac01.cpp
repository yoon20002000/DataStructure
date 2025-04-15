#include "StackPrac01.h"

#include <cstring>
#include <iterator>

StackPrac01::StackPrac01(int newCapacity) : capacity(0),size(0)
{
    if (newCapacity <= 0)
    {
        newCapacity = 1;
    }
    reserve(newCapacity);
}

StackPrac01::~StackPrac01()
{
    if (datas != nullptr)
    {
        delete[] datas;
    }
}

void StackPrac01::reserve(int newCapacity)
{
    if (newCapacity <= capacity)
    {
        return;
    }

    int* newDatas = new int[newCapacity];
    std::memcpy(newDatas, datas, size * sizeof(int));
    delete[] datas;
    datas = newDatas;
}
void StackPrac01::push(int newData)
{
    if (capacity == size)
    {
        int newCapacity = capacity * 1.5f;
        if (newCapacity < capacity)
        {
            newCapacity++;
        }
        
        reserve(newCapacity);
    }
    
    datas[size] = newData;
    size++;
}
int StackPrac01::pop()
{
    if (size <1)
    {
        return -1;
    }
    int returnValue = datas[size-1];
    size--;
    return returnValue;
}