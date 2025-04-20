#pragma once

class Queue05
{
public:
    Queue05();
    Queue05(int capacity);
    ~Queue05();
    Queue05(const Queue05& other);
    Queue05& operator=(const Queue05& other);
    Queue05(Queue05&& other) noexcept;
    Queue05& operator=(Queue05&& other) noexcept;

    
    void enqueue(int val);
    int dequeue();

    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;

    void createQueue(int inCapacity);
    void deleteQueue();
    int* queue;
    int front;
    int rear;
    int capacity;
};
