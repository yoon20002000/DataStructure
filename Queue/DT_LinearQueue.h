#pragma once

class DT_LinearQueue
{
public:
    DT_LinearQueue(int capacity = 5);
    DT_LinearQueue(const DT_LinearQueue& other) = delete;
    DT_LinearQueue& operator=(const DT_LinearQueue& other) = delete;
    DT_LinearQueue(DT_LinearQueue&& other) = delete;
    DT_LinearQueue& operator=(DT_LinearQueue&& other) = delete;
    ~DT_LinearQueue();
    void enQueue(int inData);
    int deQueue();
    bool isEmpty();
    bool isFull();
private:
    int front;
    int rear;
    int capacity;
    int* data;
};
