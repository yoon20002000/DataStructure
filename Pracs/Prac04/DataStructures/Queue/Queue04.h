#pragma once

class Queue04Node
{
public:
    Queue04Node();
    Queue04Node(int data, Queue04Node* next = nullptr);
    ~Queue04Node();
    Queue04Node(const Queue04Node& other) = delete;
    Queue04Node& operator=(const Queue04Node& other) = delete;
    Queue04Node(Queue04Node&& other) noexcept;
    Queue04Node& operator=(Queue04Node&& other)noexcept;
    
public:
    int data;
    Queue04Node* next;
};

class Queue04
{
public:
    Queue04();
    ~Queue04();
    Queue04(const Queue04& other);
    Queue04& operator=(const Queue04& other);
    Queue04(Queue04&& other) noexcept;
    Queue04& operator=(Queue04&& other)noexcept;

    int peek() const;
    void enqueue(int data);
    void dequeue();
    bool isEmpty() const;
private:
    void copyFrom(const Queue04& other);
    void clear();
public:
    Queue04Node* front;
    Queue04Node* rear;
};
