#pragma once

class DT_CycleQueue
{
public:
    DT_CycleQueue();
    DT_CycleQueue(const DT_CycleQueue& other) = delete;
    DT_CycleQueue& operator=(const DT_CycleQueue& other) = delete;
    DT_CycleQueue(DT_CycleQueue&& other) = delete;
    DT_CycleQueue& operator=(DT_CycleQueue&& other) = delete;
    ~DT_CycleQueue();
    void enQueue(int inData);
    int deQueue();
    bool isEmpty()const;
    bool isFull()const ;
    void printQueue()const;
private:
    static const int MAX_QUEUE_SIZE = 10;
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
};
