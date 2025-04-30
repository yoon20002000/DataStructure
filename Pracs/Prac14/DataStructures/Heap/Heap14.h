#pragma once
#include <optional>
#include <vector>

class Heap14
{
public:
    Heap14() = default;
    ~Heap14() = default;
    Heap14(const Heap14&) = default;
    Heap14& operator=(const Heap14&) = default;
    Heap14(Heap14&& other) noexcept;
    Heap14& operator=(Heap14&& other) noexcept;

    void insert(int value);
    std::optional<int> extractMax();
    std::optional<int> peek() const;
    bool isEmpty() const
    {
        return heap.empty();
    }
private:
    int parent(int index)const
    {
        return(index-1)/2;
    }
    int left(int index)const
    {
        return(index*2)+1;
    }
    int right(int index)const
    {
        return(index*2)+2;
    }

    void heapifyUp(int index);
    void heapifyDown(int index);
    
private:
    std::vector<int> heap;
};
