#pragma once
#include <optional>
#include <vector>

class Heap11
{
public:
    Heap11();
    ~Heap11();
    Heap11(const Heap11&) = default;
    Heap11& operator=(const Heap11&) = default;
    Heap11(Heap11&& other) noexcept;
    Heap11& operator=(Heap11&& other) noexcept;

    void insert(int value);
    std::optional<int> extractMax();

    void heapifyUp(size_t index);
    void heapifyDown(size_t index);

    bool isEmpty() const;

private:
    inline size_t parent(size_t index) const
    {
        return (index -1) / 2;
    }

    inline size_t left(size_t index) const
    {
        return index * 2 + 1;
    }
    inline size_t right(size_t index) const
    {
        return index * 2 + 2;
    }
    
private:
    std::vector<int> heap;
};
