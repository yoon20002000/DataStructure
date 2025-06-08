#pragma once
#include <optional>
#include <vector>

class Heap16
{
private:
    int getLeft(int index)const
    {
        return 2*index -1;
    }
    int getRight(int index)const
    {
        return 2*index + 1;
    }

    int getParent(int index) const
    {
        return (index - 1) / 2;
    }

    void insert(int value);
    std::optional<int> extractMax();
    void heaptifyUp(int index);
    void heapifyDown(int index);
    
    std::vector<int> heap;
};
