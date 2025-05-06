#include "Heap15.h"

Heap15::Heap15(Heap15&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap15& Heap15::operator=(Heap15&& other) noexcept
{
    if (&other != this)
    {
        heap = std::move(other.heap);
    }
    return *this;
}

void Heap15::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

std::optional<int> Heap15::extractMax()
{
    if (heap.empty())
    {
        return std::nullopt;
    }
    int returnValue = heap[0];
    heap[0]=heap.back();
    heap.pop_back();
    heapifyDown(0);
    
    return returnValue;
}

void Heap15::heapifyUp(int index)
{
    while (index > 0 && heap[index]> heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap15::heapifyDown(int index)
{
    while (true)
    {
        int l = left(index);
        int r = right(index);
        int largest = index;

        if (l < heap.size() && heap[l]>heap[largest])
        {
            largest = l;
        }
        
        if (r < heap.size() && heap[r]>heap[largest])
        {
            largest = r;
        }
        
        if (largest != index)
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
