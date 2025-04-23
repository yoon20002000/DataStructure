#pragma once

class Queue08
{
public:
    Queue08(int inCapacity = 1);
    ~Queue08();
    Queue08(const Queue08& other);
    Queue08& operator=(const Queue08& other);
    Queue08(Queue08&& other) noexcept;
    Queue08& operator=(Queue08&& other) noexcept;

    void enqueue(int value);
    int dequeue();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;

private:
    int* arr;
    int front;
    int back;
    int capacity;
};
