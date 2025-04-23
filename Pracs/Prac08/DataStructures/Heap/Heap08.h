#pragma once
#include <vector>

class Heap08
{
public:
    Heap08() = default;
    ~Heap08() = default;
    Heap08(const Heap08& other);
    Heap08& operator=(const Heap08& other);
    Heap08(Heap08&& other) noexcept;
    Heap08& operator=(Heap08&& other) noexcept;

    inline int parent(int index)
    {
        return (index - 1) / 2;
    }
    inline int left(int index)
    {
        return 2*index + 1;
    }
    inline int right(int index)
    {
        return 2*index + 2;
    }
    
    void insert(int value);
    int extractMax();

    void heapifyUp(int index);
    void heapifyDown(int index);

    inline bool isEmpty() const
    {
        return heap.empty();
    }
    
private:
    std::vector<int> heap;
};
