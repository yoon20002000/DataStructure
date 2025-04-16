#pragma once

class LinkedListQueueNodePrac02
{
public:
    LinkedListQueueNodePrac02(int data, LinkedListQueueNodePrac02* prev, LinkedListQueueNodePrac02* next);
    ~LinkedListQueueNodePrac02();
    LinkedListQueueNodePrac02(const LinkedListQueueNodePrac02& other) = delete;
    LinkedListQueueNodePrac02& operator=(const LinkedListQueueNodePrac02& other) = delete;
    LinkedListQueueNodePrac02(LinkedListQueueNodePrac02&& other) noexcept;
    LinkedListQueueNodePrac02& operator=(LinkedListQueueNodePrac02&& other) noexcept;
    
    int data;
    LinkedListQueueNodePrac02* prev;
    LinkedListQueueNodePrac02* next;
};

class QueuePrac02
{
public:
    QueuePrac02();
    ~QueuePrac02();
    QueuePrac02(const QueuePrac02& other);
    QueuePrac02& operator=(const QueuePrac02& other);
    QueuePrac02(QueuePrac02&& other) noexcept;
    QueuePrac02& operator=(QueuePrac02&& other) noexcept;
    int frontData() const;
    int backData() const;
    void enqueue(int data);
    int dequeue();
    bool isEmpty() const;
    
    int size;
    LinkedListQueueNodePrac02* front;
    LinkedListQueueNodePrac02* rear;
};
