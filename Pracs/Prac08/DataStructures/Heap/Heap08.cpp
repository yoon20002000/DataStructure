#include "Heap08.h"

#include <iostream>

Heap08::Heap08(const Heap08& other)
{
    heap = other.heap;
}

Heap08& Heap08::operator=(const Heap08& other)
{
    if (&other != this)
    {
        heap = other.heap;    
    }
    return *this;
}

Heap08::Heap08(Heap08&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap08& Heap08::operator=(Heap08&& other) noexcept
{
    if (&other != this)
    {
        heap = std::move(other.heap);    
    }
    
    return *this;
}

void Heap08::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int Heap08::extractMax()
{
    if (isEmpty())
    {
        std::cout<< "Heap is empty"<<'\n';
        return -1;
    }
    int returnValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return returnValue;
}

void Heap08::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap08::heapifyDown(int index)
{
    int l = left(index);
    int r = right(index);
    int largest = index;

    while (true)
    {
        if (l < heap.size() && heap[l] > heap[largest])
        {
            largest = l;
        }

        if (r < heap.size() && heap[r] > heap[largest])
        {
            largest = r;
        }

        if (largest!=index)
        {
            std::swap(heap[largest], heap[index]);
            index = largest;
        }
        else
        {
            break;
        }
    }
}
