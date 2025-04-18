#include "Heap03.h"

#include <fstream>
#include <memory>
#include <unordered_map>

Heap03::Heap03()
{
}

Heap03::~Heap03()
{
}

Heap03::Heap03(const Heap03& other)
{
    heap = other.heap;
}

Heap03& Heap03::operator=(const Heap03& other)
{
    heap = other.heap;
    return *this;
}

Heap03::Heap03(Heap03&& other) noexcept
{
    heap = std::move(other.heap);
}

Heap03& Heap03::operator=(Heap03&& other) noexcept
{
    heap = std::move(other.heap);

    return *this;
}

int Heap03::parent(int index)
{
    return (index - 1) / 2;
}

int Heap03::left(int index)
{
    return 2 * index + 1;
}

int Heap03::right(int index)
{
    return 2 * index + 2;
}

bool Heap03::isEmpty()
{
    return heap.empty();
}

void Heap03::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

void Heap03::deleteData(int value)
{
    if (isEmpty())
    {
        return;
    }
    
    auto iter = std::find(heap.begin(), heap.end(), value);
    if (iter == heap.end())
    {
        return;
    }

    int index = std::distance(heap.begin(), iter);
    heap[index] = heap.back();
    heap.pop_back();
    heapifyDown(index);
}

int Heap03::extractMax()
{
    if (isEmpty())
    {
        return -1;
    }

    int returnValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    
    return returnValue;
}

void Heap03::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void Heap03::heapifyDown(int index)
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
        heapifyDown(largest);
    }
}

void Heap03::heapifyDownWhile(int index)
{
    while (true)
    {
        int l = left(index);
        int r = right(index);
        int largest = index;

        if (l < heap.size() && heap[l] > heap[index])
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
