#include "Heap05.h"

#include <cassert>
#include <memory>
Heap05::Heap05()
{
}

Heap05::~Heap05()
{
}

Heap05::Heap05(const Heap05& other)
{
    heap = other.heap;
}

Heap05& Heap05::operator=(const Heap05& other)
{
    if (this != &other)
    {
        heap = other.heap;
    }
    return *this;
}

Heap05::Heap05(Heap05&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap05& Heap05::operator=(Heap05&& other) noexcept
{
    if (this != &other)
    {
        heap = std::move(other.heap);
    }
    return *this;
}

bool Heap05::isEmpty() const
{
    return heap.empty();
}

void Heap05::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int Heap05::extractMax()
{
    if (isEmpty())
    {
        return -1;
    }
    
    int max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    
    heapifyDown(0);
    return max;
}

int Heap05::parent(int index) const
{
    assert(index > 0);
    return (index-1)/2;
}

int Heap05::left(int index) const
{
    return 2*index + 1;
}

int Heap05::right(int index) const
{
    return 2*index + 2;
}

void Heap05::heapifyUp(int index)
{
    while (index > 0 && heap[index]> heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap05::heapifyDown(int index)
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
