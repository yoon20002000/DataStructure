#pragma once

class Queue09
{
public:
    Queue09(int inCapacity);
    ~Queue09();
    Queue09(const Queue09& other);
    Queue09& operator=(const Queue09& other);
    Queue09(Queue09&& other) noexcept;
    Queue09& operator=(Queue09&& other) noexcept;

    void enqueue(int value);
    int dequeue();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    
private:
    int* queue;
    int capacity;
    int front;
    int back;
};
