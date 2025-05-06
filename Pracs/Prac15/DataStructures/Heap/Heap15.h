#pragma once
#include <optional>
#include <vector>

class Heap15
{
public:
    Heap15() = default;
    ~Heap15() = default;
    Heap15(const Heap15& other) = default;
    Heap15& operator=(const Heap15& other) = default;
    Heap15(Heap15&& other) noexcept;
    Heap15& operator=(Heap15&& other) noexcept;

    void insert(int value);
    std::optional<int> extractMax();

private:
    int parent(int index) const
    {
        return (index - 1) / 2;
    }
    int left(int index) const
    {
        return 2*index + 1;
    }
    int right(int index) const
    {
        return 2*index + 2;
    }
    void heapifyUp(int index);
    void heapifyDown(int index);
private:
    std::vector<int> heap;
};
