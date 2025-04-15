#include "HeapPrac01.h"

#include <fstream>

HeapPrac01::HeapPrac01()
{
    heap.reserve(10);
}

int HeapPrac01::parent(int i)
{
    return (i-1)/2;
}

int HeapPrac01::left(int i)
{
    return 2* i + 1;
}

int HeapPrac01::right(int i)
{
    return 2* i + 2;
}

void HeapPrac01::heapifyUp(int i)
{
    while (i > 0 && heap[i] > heap[parent(i)])
    {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void HeapPrac01::heapifyDown(int i)
{
    int left = left(i);
    int right = right(i);
    int largest = i;

    int size = heap.size();
    while (true)
    {
        if (left <  size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            std::swap(heap[i], heap[largest]);
        }
        else
        {
            break;
        }
    }
    
    
}
