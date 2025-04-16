#pragma once
#include <vector>

class HeapPrac02
{
public:
    HeapPrac02();
    HeapPrac02(int capacity);
    ~HeapPrac02();
    HeapPrac02(const HeapPrac02& other);
    HeapPrac02& operator=(const HeapPrac02& other);
    HeapPrac02(HeapPrac02&& other) noexcept;
    HeapPrac02& operator=(HeapPrac02&& other) noexcept;

    int parent(int index);
    int left(int index);
    int right(int index);

    void push(int data);
    void pop();
    int peek();

    void heapifyUp(int index);
    void heapifyDown(int index);
    void makeHeapify(int index);
    std::vector<int> heap;
};
