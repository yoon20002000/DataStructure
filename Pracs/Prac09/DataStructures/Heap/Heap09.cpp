#include "Heap09.h"

#include <iostream>
#include <memory>

Heap09::Heap09(const Heap09& other) : heap(other.heap)
{
}

Heap09& Heap09::operator=(const Heap09& other)
{
    if (&other != this)
    {
        heap = other.heap;
    }
    return *this;
}

Heap09::Heap09(Heap09&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap09& Heap09::operator=(Heap09&& other) noexcept
{
    if (&other != this)
    {
        heap = std::move(other.heap);
    }
    return *this;
}

void Heap09::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int Heap09::extractMax()
{
    if (isEmpty())
    {
        std::cout << "Heap empty-" << '\n';
        return -1;
    }
    int returnValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return returnValue;
}

bool Heap09::isEmpty() const
{
    return heap.empty();
}

void Heap09::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap09::heapifyDown(int index)
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
