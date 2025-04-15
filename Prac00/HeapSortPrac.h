#pragma once
#include <vector>

class HeapSortPrac
{
public:
private:
    int parent(int index)
    {
        return (index - 1) / 2;
    }
    int left ( int index)
    {
        return 2*index +1;
    }
    int right ( int index)
    {
        return 2*index +2;
    }
    void HeapifyUp(int index);
    void HeapifyDown(int index);
    void Insert(int data);
    int ExtractMax();

    std::vector<int> datas;
};
