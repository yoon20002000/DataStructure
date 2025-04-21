#pragma once
#include <vector>

class Heap06
{
public:
    Heap06();
    ~Heap06();
    Heap06(const Heap06& other);
    Heap06& operator=(const Heap06& other);
    Heap06(Heap06&& other) noexcept;
    Heap06& operator=(Heap06&& other) noexcept;

    int parent(int index) const;
    int left(int index) const;
    int right(int index) const;


    bool isEmpty();
    int extractMax();
    void insert(int data);

    void heapifyUp(int index);
    void heapifyDown(int index);

private:
    std::vector<int> heap;
};
