#pragma once
#include <vector>

class DT_Heap
{
public:
    DT_Heap();
    void insert(int val);
    int extractMax();
    int peek() const;
    bool isEmpty() const;
    void print() const;
private:
    std::vector<int> heap;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }

    void heapifyUp(int i);
    void heapifyDown(int i);
};
