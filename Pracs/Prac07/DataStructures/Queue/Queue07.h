#pragma once

class Queue07
{
public:
    Queue07(int size);
    ~Queue07();
    Queue07(const Queue07& other);
    Queue07& operator=(const Queue07& other);
    Queue07(Queue07&& other) noexcept;
    Queue07& operator=(Queue07&& other) noexcept;

    void enqueue(int value);
    int dequeue();
    int peak() const;
    int size() const;
    bool isEmpty() const;
    bool isFull() const;
    
private:
    int* data;
    int capacity;
    int front;
    int rear;
};
