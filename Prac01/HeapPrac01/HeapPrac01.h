#pragma once
#include <vector>

class HeapPrac01
{
public:
    HeapPrac01();
    int parent(int i);
    int left(int i);
    int right(int i);

    std::vector<int> heap;

    void heapifyUp(int i);
    void heapifyDown(int i);
};
