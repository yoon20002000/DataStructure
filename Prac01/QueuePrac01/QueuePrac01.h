#pragma once

class QueuePrac01
{
public:
    QueuePrac01(int capacity);
    ~QueuePrac01();
    void enqueue(int data);
    int dequeue();
    int front;
    int rear;
    int* datas;
    int capacity;
};
