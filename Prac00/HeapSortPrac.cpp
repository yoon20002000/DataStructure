#include "HeapSortPrac.h"

#include <fstream>

void HeapSortPrac::HeapifyUp(int index)
{
    while (index > 0 && datas[index] < datas[parent(index)])
    {
        std::swap(datas[index], datas[parent(index)]);
        index = parent(index);
    }
}

void HeapSortPrac::HeapifyDown(int index)
{
    while (true)
    {
        int largeIndex = index;
        int leftIndex = leftIndex(index);
        int rightIndex = rightIndex(index);

        if (datas[largeIndex] < datas[leftIndex])
        {
            largeIndex = leftIndex;
        }

        if (datas[largeIndex] < datas[rightIndex])
        {
            largeIndex = rightIndex;
        }
        if (largeIndex != index)
        {
            std::swap(datas[index], datas[largeIndex]);    
        }
        else
        {
            break;
        }
    }
}

void HeapSortPrac::Insert(int data)
{
    datas.push_back(data);
    HeapifyUp(datas.size() - 1);
}

int HeapSortPrac::ExtractMax()
{
    int deleteTarget = datas[0];
    datas[0] = datas.back();
    datas.pop_back();
    HeapifyDown(0);
    return deleteTarget;
}
