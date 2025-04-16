#include "HeapPrac02.h"

#include <memory>

HeapPrac02::HeapPrac02()
{
    heap.reserve(10);
}

HeapPrac02::HeapPrac02(int capacity)
{
    heap.reserve(capacity);
}

HeapPrac02::~HeapPrac02()
{
    heap.clear();
}

HeapPrac02::HeapPrac02(const HeapPrac02& other)
{
    heap = other.heap;
}

HeapPrac02& HeapPrac02::operator=(const HeapPrac02& other)
{
    heap = other.heap;
    return *this;
}

HeapPrac02::HeapPrac02(HeapPrac02&& other) noexcept
{
    heap = std::move(other.heap);
    other.heap.clear();
}

HeapPrac02& HeapPrac02::operator=(HeapPrac02&& other) noexcept
{
    if (&other == this)
    {
        return *this;
    }
    heap.clear();
    heap = std::move(other.heap);
    other.heap.clear();
    return *this;
}

int HeapPrac02::parent(int index)
{
    return (index - 1) / 2;
}

int HeapPrac02::left(int index)
{
    return 2 * index + 1;
}

int HeapPrac02::right(int index)
{
    return 2 * index + 2;
}

void HeapPrac02::push(int data)
{
    heap.push_back(data);
    heapifyUp(heap.size() - 1);
}

void HeapPrac02::pop()
{
    if (heap.empty())
    {
        return;
    }

    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

int HeapPrac02::peek()
{
    if (heap.empty())
    {
        return -1;
    }
    return heap[0];
}

void HeapPrac02::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)])
    {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void HeapPrac02::heapifyDown(int index)
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

void HeapPrac02::makeHeapify(int index)
{
    // int l = left(index);
    // int r = right(index);
    // int largest = index;
    //
    // if (l < heap.size() && heap[l] > heap[largest])
    // {
    //     largest = l;    
    // }
    //
    // if (r < heap.size() && heap[r] > heap[largest])
    // {
    //     largest = r;
    // }
    //
    // if (largest != index)
    // {
    //     std::swap(heap[index], heap[largest]);
    //     makeHeapify(largest);
    // }

    while (index < heap.size())
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
