#include "DT_Heap.h"

#include <iostream>
#include <ostream>

DT_Heap::DT_Heap()
{
    heap.reserve(10);
}

void DT_Heap::insert(int val)
{
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

int DT_Heap::extractMax()
{
    if (heap.empty())
    {
        std::cout << "Heap is empty" << '\n';
        return -1;
    }
    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return maxVal;
}

int DT_Heap::peek() const
{
    if (heap.empty())
    {
        std::cout << "Heap is empty" << '\n';
        return -1;
    }
    return heap[0];
}

bool DT_Heap::isEmpty() const
{
    return heap.empty();
}

void DT_Heap::print() const
{
    for (int h : heap)
    {
        std::cout<< h << " ";
    }
    std::cout << '\n';
}

void DT_Heap::heapifyUp(int i)
{
    while (i >0 &&heap[i] > heap[parent(i)])
    {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }  
}

void DT_Heap::heapifyDown(int i)
{
    int size = heap.size();
    while (true)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && heap[l] > heap[largest])
        {
            largest = l;
        }
        if (r < size && heap[r] > heap[largest])
        {
            largest = r;
        }

        if (largest != i)
        {
            std::swap(heap[i], heap[largest]);
            i = largest;
        }
        else
        {
            break;
        }
    }
}
