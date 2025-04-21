#include "Heap06.h"

#include <memory>

Heap06::Heap06() : heap()
{
}

Heap06::~Heap06()
{
}

Heap06::Heap06(const Heap06& other)
{
    heap = other.heap;
}

Heap06& Heap06::operator=(const Heap06& other)
{
    if (&other != this)
    {
        heap = other.heap;
    }
    return *this;
}

Heap06::Heap06(Heap06&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap06& Heap06::operator=(Heap06&& other) noexcept
{
    if (&other != this)
    {
        heap = std::move(other.heap);
    }
    return *this;
}

int Heap06::parent(int index) const
{
    return (index - 1) / 2;
}

int Heap06::left(int index) const
{
    return 2 * index + 1;
}

int Heap06::right(int index) const
{
    return 2 * index + 2;
}

bool Heap06::isEmpty()
{
    return heap.empty();
}

int Heap06::extractMax()
{
    if (isEmpty())
    {
        return -1;
    }

    int returnVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return returnVal;
}

void Heap06::insert(int data)
{
    heap.push_back(data);
    heapifyUp(heap.size() - 1);
}

void Heap06::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap06::heapifyDown(int index)
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
