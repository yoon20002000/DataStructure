#include "Heap04.h"

#include <memory>

Heap04::Heap04()
{
}

Heap04::~Heap04()
{
}

Heap04::Heap04(const Heap04& other)
{
    heap = other.heap;
}

Heap04& Heap04::operator=(const Heap04& other)
{
    if (&other != this)
    {
        heap = other.heap;    
    }
    
    return *this;
}

Heap04::Heap04(Heap04&& other) noexcept
{
    heap = std::move(other.heap);
    other.heap.clear();
}

Heap04& Heap04::operator=(Heap04&& other) noexcept
{
    if (&other != this)
    {
        heap = std::move(other.heap);
        other.heap.clear();
    }
    return *this;
}

int Heap04::parent(int index) const
{
    return (index - 1) / 2;
}

int Heap04::left(int index) const
{
    return 2*index + 1;
}

int Heap04::right(int index) const
{
    return 2*index + 2;
}

void Heap04::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

void Heap04::popMax()
{
    if (isEmpty())
    {
        return;
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

int Heap04::peekMax() const
{
    if (isEmpty())
    {
        return -1;
    }
    return heap[0];
}

bool Heap04::isEmpty() const
{
    return heap.empty();
}

void Heap04::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap04::heapifyDown(int index)
{
    while (true)
    {
        int largest = index;
        int left = left(index);
        int right = right(index);
        
        if (left < heap.size() && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (index!= largest)
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
