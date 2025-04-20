#pragma once
#include <vector>

class Heap05
{
public:
    Heap05();
    ~Heap05();
    Heap05(const Heap05& other);
    Heap05& operator=(const Heap05& other);
    Heap05(Heap05&& other) noexcept;
    Heap05& operator=(Heap05&& other) noexcept;
    bool isEmpty() const;
    void insert(int value);
    int extractMax();

    int parent(int index) const;
    int left(int index) const;
    int right(int index) const;
    
    void heapifyUp(int index);
    void heapifyDown(int index);
    
    
    std::vector<int> heap;
};
