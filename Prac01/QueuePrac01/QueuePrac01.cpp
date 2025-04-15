#include "QueuePrac01.h"

QueuePrac01::QueuePrac01(int capacity) : front(0), rear(0),capacity(capacity)
{
    datas = new int[capacity];
}

QueuePrac01::~QueuePrac01()
{
    delete[] datas;
}

void QueuePrac01::enqueue(int data)
{
    if ((rear+1)%capacity == front)
    {
        return;
    }

    datas[rear] = data;
    rear = (rear + 1) % capacity;
}

int QueuePrac01::dequeue()
{
    if (front == rear)
    {
        return -1;
    }
    int returnValue=  datas[front];
    front = (front +1) % capacity;
    return returnValue;
}
