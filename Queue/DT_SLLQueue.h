#pragma once

class SingleLinkedListNode
{
public:
    SingleLinkedListNode(int inData, SingleLinkedListNode* nextNode = nullptr) : data(inData), next(nextNode)
    {
        
    }
    
public:
    int data;
    SingleLinkedListNode* next;
};

class DT_SLLQueue
{
public:
    DT_SLLQueue();
    ~DT_SLLQueue();
    DT_SLLQueue(const DT_SLLQueue& other) = delete;
    DT_SLLQueue& operator=(const DT_SLLQueue& other) = delete;
    DT_SLLQueue(DT_SLLQueue&& other) = delete;
    DT_SLLQueue& operator=(DT_SLLQueue&& other) = delete;
    
    void enqueue(int data);
    int dequeue();
    int peek() const;
    SingleLinkedListNode* front;
    SingleLinkedListNode* rear;
};
