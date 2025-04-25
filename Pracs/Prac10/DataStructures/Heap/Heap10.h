#pragma once
#include <optional>
#include <vector>

class Heap10
{
public:
    Heap10() = default;
    ~Heap10() = default;
    Heap10(const Heap10&) = default;
    Heap10& operator=(const Heap10&) = default;
    Heap10(Heap10&& other) noexcept;
    Heap10& operator=(Heap10&& other) noexcept;

    inline int parent(int index) const
    {
        return (index - 1) / 2;
    }
    inline int left(int index) const
    {
        return (index * 2) + 1;
    }
    inline int right(int index) const
    {
        return (index * 2) + 2;
    }
    
    void insert(int value);
    std::optional<int> extractMax();
    inline  bool isEmpty() const
    {
        return heap.empty();
    }

    void heapifyUp(int index);
    void heapifyDown(int index);
    void makeMaxHeap();
private:
    std::vector<int> heap;
};
