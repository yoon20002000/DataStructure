#include "Queue06.h"

Queue06Node::Queue06Node(int data, Queue06Node* next) : data(data), next(next)
{
}

Queue06Node::~Queue06Node()
{
}

int Queue06Node::getData() const
{
    return data;
}

void Queue06Node::setData(int inData)
{
    data = inData;
}

Queue06Node* Queue06Node::getNext() const
{
    return next;
}

void Queue06Node::setNext(Queue06Node* inNext)
{
    next = inNext;
}
Queue06::Queue06(): size(0), front(nullptr), back(nullptr)
{
}

Queue06::~Queue06()
{
    deleteQueue();
}

void Queue06::enqueue(int data)
{
    Queue06Node* newNode = new Queue06Node(data, nullptr);

    if (front == nullptr)
    {
        front = back = newNode;
    }
    else
    {
        back->setNext(newNode);
        back = newNode;
    }
    ++size;
}

int Queue06::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }

    int returnValue = front->getData();
    Queue06Node* nextFront = front->getNext();
    delete front;
    front = nextFront;

    if (front == nullptr)
    {
        back = nullptr;
    }
    --size;
    return returnValue;
}

bool Queue06::isEmpty() const
{
    return front == nullptr;
}

int Queue06::getSize() const
{
    return size;
}

void Queue06::deleteQueue()
{
    while (front != nullptr)
    {
        dequeue();
    }
}
