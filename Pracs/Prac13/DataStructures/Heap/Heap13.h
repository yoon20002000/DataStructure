#pragma once
#include <optional>
#include <vector>

class Heap13
{
public:
    Heap13() = default;
    ~Heap13() = default;
    Heap13(const Heap13& other) = default;
    Heap13& operator=(const Heap13& other) = default;
    Heap13(Heap13&& other) noexcept;
    Heap13& operator=(Heap13&& other) noexcept;

    void insert(int value);
    std::optional<int> extractMax();

    bool isEmpty() const
    {
        return heap.empty();
    }

    int parent(int index) const
    {
        return (index - 1) / 2;
    }

    int left(int index) const
    {
        return 2 * index + 1;
    }

    int right(int index) const
    {
        return 2 * index + 2;
    }

    void heapifyUp(int index);
    void heapifyDown(int index);

private:
    std::vector<int> heap;
};
