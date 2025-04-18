#pragma once
#include <vector>

class Heap04
{
public:
    Heap04();
    ~Heap04();
    Heap04(const Heap04& other);
    Heap04& operator=(const Heap04& other);
    Heap04(Heap04&& other) noexcept;
    Heap04& operator=(Heap04&& other) noexcept;

    int parent(int index) const;
    int left(int index) const;
    int right(int index) const;
    
    void insert(int value);
    void popMax();
    int peekMax() const;
    bool isEmpty() const;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    std::vector<int> heap;
};
