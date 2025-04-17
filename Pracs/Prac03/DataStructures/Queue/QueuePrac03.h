#pragma once

class QueuePrac03Node
{
public:
    QueuePrac03Node();
    QueuePrac03Node(int data, QueuePrac03Node* next = nullptr );
    ~QueuePrac03Node();
    QueuePrac03Node(const QueuePrac03Node&) = delete;
    QueuePrac03Node& operator=(const QueuePrac03Node&) = delete;
    QueuePrac03Node(QueuePrac03Node&& other) noexcept;
    QueuePrac03Node& operator=(QueuePrac03Node&& other) noexcept;
public:
    int data;
    QueuePrac03Node* next;
};

class QueuePrac03
{
public:
    QueuePrac03();
    ~QueuePrac03();
    QueuePrac03(const QueuePrac03& other);
    QueuePrac03& operator=(const QueuePrac03& other);
    QueuePrac03(QueuePrac03&& other) noexcept;
    QueuePrac03& operator=(QueuePrac03&& other) noexcept;
    
    void enqueue(int data);
    void dequeue();
    int peek();
    int getSize() const;
    bool isEmpty() const;
private:
    void deleteNodes();
private:
    QueuePrac03Node* front;
    QueuePrac03Node* rear;
    int size;
};
