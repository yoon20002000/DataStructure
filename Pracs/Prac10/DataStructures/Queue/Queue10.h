#pragma once
#include <optional>

class Queue10
{
public:
    Queue10(int inCapacity = 10);
    ~Queue10();
    Queue10(const Queue10& other);
    Queue10& operator=(const Queue10& other);
    Queue10(Queue10&& other) noexcept;
    Queue10& operator=(Queue10&& other) noexcept;

    void enqueue(int value);
    std::optional<int> dequeue();
    std::optional<int> peek() const;
    bool isEmpty() const;
    bool isFull() const;
private:
    int* arr;
    int front;
    int back;
    int capacity;
};
