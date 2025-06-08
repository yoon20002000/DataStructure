#include "Heap16.h"

void Heap16::insert(int value)
{
    heap.push_back(value);
    heaptifyUp(heap.size() - 1);
}

std::optional<int> Heap16::extractMax()
{
    if (heap.empty())
    {
        return std::nullopt;
    }

    int returnValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return returnValue;
}

void Heap16::heaptifyUp(int index)
{
    while (index > 0 && heap[index] > heap[getParent(index)])
    {
        std::swap(heap[index], heap[getParent(index)]);
        index = getParent(index);
    }
}

void Heap16::heapifyDown(int index)
{
    while (true)
    {
        int left = getLeft(index);
        int right = getRight(index);
        int largest = index;
    
        if (left < heap.size() - 1 && heap[left] > heap[largest])
        {
            largest = left;
        }
        else if (right < heap.size() - 1 && heap[right] > heap[largest])
        {
            largest = right;
        }
        else
        {
            break;
        }
        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}
