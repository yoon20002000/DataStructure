#include "Heap07.h"

#include <memory>

Heap07::Heap07(const Heap07& other)
{
    heap = other.heap;
}

Heap07& Heap07::operator=(const Heap07& other)
{
    if (&other != this)
    {
        heap = other.heap;    
    }
    return *this;
}

Heap07::Heap07(Heap07&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap07& Heap07::operator=(Heap07&& other) noexcept
{
    if (&other != this)
    {
        heap = std::move(other.heap);
    }
    return *this;
}

int Heap07::parent(int index) const
{
    return (index-1) / 2;
}

int Heap07::left(int index) const
{
    return 2 * index + 1;
}

int Heap07::right(int index) const
{
    return 2 * index + 2;
}

void Heap07::insert(int data)
{
    heap.push_back(data);
    heapifyUp(heap.size() - 1);
}

int Heap07::extractMax()
{
    if (heap.empty())
    {
        return -1;
    }
    
    int returnValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    heapifyDown(0);
    
    return returnValue;
}

void Heap07::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap07::heapifyDown(int index)
{
    while (true)
    {
        int l = left(index);
        int r = right(index);
        int largest = index;

        if (l < heap.size() && heap[l] > heap[largest])
        {
            largest = l;
        }

        if (r < heap.size() && heap[r] > heap[largest])
        {
            largest = r;
        }
        
        if (index != largest)
        {
            std::swap(heap[index], heap[largest]);
            index = largest;
        }
        else
        {
            break;
        }
    }
}
