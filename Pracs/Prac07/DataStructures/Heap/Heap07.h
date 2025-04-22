#pragma once
#include <vector>

class Heap07
{
public:
    Heap07() = default;
    ~Heap07() = default;
    Heap07(const Heap07& other);
    Heap07& operator=(const Heap07& other);
    Heap07(Heap07&& other) noexcept;
    Heap07& operator=(Heap07&& other) noexcept;

    int parent(int index) const;
    int left(int index) const;
    int right(int index) const;

    void insert(int data);
    int extractMax();

    void heapifyUp(int index);
    void heapifyDown(int index);
    
private:
    std::vector<int> heap;
};
