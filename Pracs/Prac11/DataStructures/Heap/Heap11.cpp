#include "Heap11.h"
#include <memory>
Heap11::Heap11() : heap()
{
}

Heap11::~Heap11()
{
}

Heap11::Heap11(Heap11&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap11& Heap11::operator=(Heap11&& other) noexcept
{
    if (this != &other)
    {
        heap = std::move(other.heap);
    }
    return *this;
}

void Heap11::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

std::optional<int> Heap11::extractMax()
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

void Heap11::heapifyUp(size_t index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap11::heapifyDown(size_t index)
{
    while (true)
    {
        size_t l = left(index);
        size_t r = right(index);
        size_t largest = index;

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
            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }
}

bool Heap11::isEmpty() const
{
    return heap.empty();
}