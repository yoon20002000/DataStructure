#pragma once
#include <vector>

class Heap09
{
public:
    Heap09() = default;
    ~Heap09() = default;
    Heap09(const Heap09& other);
    Heap09& operator=(const Heap09& other);
    Heap09(Heap09&& other) noexcept;
    Heap09& operator=(Heap09&& other) noexcept;

    inline int parent(int index) const
    {
        return (index - 1) / 2;
    }
    
    inline int left(int index) const
    {
        return 2*index + 1;
    }
    inline int right(int index) const
    {
        return 2*index + 2;
    }
    
    void insert(int value);
    int extractMax();
    bool isEmpty() const;

    void heapifyUp(int index);
    void heapifyDown(int index);

    void buildHeap();
private:
    std::vector<int> heap;
};
