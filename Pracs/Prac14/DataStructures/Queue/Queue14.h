#pragma once
#include <optional>

class Queue14
{
public:
    Queue14(size_t inCapacity = 1);
    ~Queue14();
    Queue14(const Queue14& other);
    Queue14& operator=(const Queue14& other);
    Queue14(Queue14&& other) noexcept;
    Queue14& operator=(Queue14&& other) noexcept;

    void enqueue(int value);
    std::optional<int> dequeue();
    std::optional<int> peek() const;

    bool isEmpty() const
    {
        return front == back;
    }

    bool isFull() const
    {
        return (back + 1) % capacity == front;
    }

private:
    void reserve(size_t inCapacity);

private:
    int* queue;
    size_t capacity;
    size_t front;
    size_t back;
};
