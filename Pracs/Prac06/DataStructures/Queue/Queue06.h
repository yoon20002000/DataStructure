#pragma once

class Queue06Node
{
public:
    Queue06Node() = delete;
    Queue06Node(int data, Queue06Node* next = nullptr);
    ~Queue06Node();
    Queue06Node(const Queue06Node&) = delete;
    Queue06Node& operator=(const Queue06Node&) = delete;
    Queue06Node(Queue06Node&&) = delete;
    Queue06Node& operator=(Queue06Node&&) = delete;

    int getData() const;
    void setData(int inData);
    Queue06Node* getNext() const;
    void setNext(Queue06Node* inNext);
    
private:
    int data;
    Queue06Node* next;
};

class Queue06
{
public:
    Queue06();
    ~Queue06();
    Queue06(const Queue06& other) = delete;
    Queue06& operator=(const Queue06& other) = delete;
    Queue06(Queue06&& other) = delete;
    Queue06& operator=(Queue06&& other) = delete;

    void enqueue(int data);
    int dequeue();

    bool isEmpty() const;
    int getSize() const;
private:
    void deleteQueue();
    
private:
    int size;
    Queue06Node* front;
    Queue06Node* back;
};
