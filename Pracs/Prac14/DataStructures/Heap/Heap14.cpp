#include "Heap14.h"

Heap14::Heap14(Heap14&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap14& Heap14::operator=(Heap14&& other) noexcept
{
    if (&other != this)
    {
        heap = std::move(other.heap);
    }
    return *this;
}

void Heap14::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

std::optional<int> Heap14::extractMax()
{
    if (isEmpty())
    {
        return std::nullopt;
    }
    int returnValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    
    return returnValue;
}

std::optional<int> Heap14::peek() const
{
    if (isEmpty())
    {
        return std::nullopt;
    }

    return heap[0];
}

void Heap14::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap14::heapifyDown(int index)
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

        if (largest == index)
        {
            break;
        }
        else
        {
            std::swap(heap[largest], heap[index]);
            index = largest;
        }
    }
}
