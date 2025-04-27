#pragma once
#include <optional>

class Queue11
{
public:
    Queue11(size_t inCapacity = 1);
    ~Queue11();
    Queue11(const Queue11& other);
    Queue11& operator=(const Queue11& other);
    Queue11(Queue11&& other) noexcept;
    Queue11& operator=(Queue11&& other) noexcept;

    void enqueue(int value);
    std::optional<int> dequeue();
    std::optional<int> peek() const; 
    bool isEmpty() const;
    bool isFull() const;

private:
    int* queue;
    size_t capacity;
    int front;
    int back;
};
