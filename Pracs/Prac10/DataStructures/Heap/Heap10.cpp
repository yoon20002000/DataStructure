#include "Heap10.h"

#include <iostream>
#include <memory>

Heap10::Heap10(Heap10&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap10& Heap10::operator=(Heap10&& other) noexcept
{
    if (&other != this)
    {
        heap = std::move(other.heap);
    }
    return *this;
}

void Heap10::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

std::optional<int> Heap10::extractMax()
{
    if (isEmpty())
    {
        std::cout << "Heap is empty.\n";
        return std::nullopt;
    }

    auto returnValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return returnValue;
}

void Heap10::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap10::heapifyDown(int index)
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

void Heap10::makeMaxHeap()
{
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
    {
        heapifyDown(i);
    }
}
