#pragma once
#include <vector>

class Heap03
{
public:
    Heap03();
    ~Heap03();
    Heap03(const Heap03& other);
    Heap03& operator=(const Heap03& other);
    Heap03(Heap03&& other) noexcept;
    Heap03& operator=(Heap03&& other) noexcept;

    int parent(int index);
    int left(int index);
    int right(int index);
    bool isEmpty();
    void insert(int value);
    void deleteData(int value);
    int extractMax();

    void heapifyUp(int index);
    void heapifyDown(int index);
    void heapifyDownWhile(int index);
    std::vector<int> heap;
};
