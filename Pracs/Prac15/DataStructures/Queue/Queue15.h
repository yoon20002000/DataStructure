#pragma once
#include <optional>

class Queue15
{
public:
    Queue15(size_t inCapacity);
    ~Queue15();
    Queue15(const Queue15& other);
    Queue15& operator=(const Queue15& other);
    Queue15(Queue15&& other) noexcept;
    Queue15& operator=(Queue15&& other) noexcept;

    void enqueue(int value);
    std::optional<int> dequeue();
    std::optional<int> peek() const; 
    bool isEmpty() const;
    bool isFull() const;
    

private:
    int* queue;
    size_t front;
    size_t back;
    size_t capacity;
};
