#pragma once
#include <optional>

class Queue16
{
public:
    Queue16();
    ~Queue16();

    void enqueue(int value);
    std::optional<int> dequeue();
    bool isEmpty() const
    {
        return front == back;
    }
    bool isFull() const
    {
        return (back + 1) % MAX_CAPACITY == front;
    }
private:
    int* queue;
    const int MAX_CAPACITY = 11;
    int front;
    int back;
};
