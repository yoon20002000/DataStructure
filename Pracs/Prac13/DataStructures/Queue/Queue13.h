#pragma once
#include <optional>

class Queue13
{
public:
    Queue13(size_t inCapacity = 1);
    ~Queue13();
    Queue13(const Queue13& other);
    Queue13& operator=(const Queue13& other);
    Queue13(Queue13&& other) noexcept;
    Queue13& operator=(Queue13&& other) noexcept;

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
    int front;
    int back;
};
