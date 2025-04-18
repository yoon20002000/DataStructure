#include "Queue04.h"

Queue04Node::Queue04Node() : data(0), next(nullptr)
{
}

Queue04Node::Queue04Node(int data, Queue04Node* next) : data(data), next(next)
{
}

Queue04Node::~Queue04Node()
{
}

Queue04Node::Queue04Node(Queue04Node&& other) noexcept
{
    data = other.data;
    next = other.next;

    other.data= 0;
    other.next = nullptr;
}

Queue04Node& Queue04Node::operator=(Queue04Node&& other) noexcept
{
    if (&other == this)
    {
        return *this;
    }
    
    data = other.data;
    next = other.next;

    other.data= 0;
    other.next = nullptr;

    return *this;
}

Queue04::Queue04() : front(nullptr), rear(nullptr)
{
}

Queue04::~Queue04()
{
    clear();   
}

Queue04::Queue04(const Queue04& other) : front(nullptr), rear(nullptr)
{
    copyFrom(other);
}

Queue04& Queue04::operator=(const Queue04& other)
{
    if (&other == this)
    {
        return *this;
    }
    clear();
    copyFrom(other);
    return *this;
}

Queue04::Queue04(Queue04&& other) noexcept
{
    front  = other.front;
    rear = other.rear;

    other.front = nullptr;
    other.rear = nullptr;
}

Queue04& Queue04::operator=(Queue04&& other) noexcept
{
    if (&other == this)
    {
        return *this;
    }

    clear();
    front = other.front;
    rear = other.rear;

    other.front = nullptr;
    other.rear = nullptr;
    
    return *this;
}

int Queue04::peek() const
{
    if (isEmpty())
    {
        return -1;
    }

    return front->data;
}

void Queue04::enqueue(int data)
{
    Queue04Node* newNode = new Queue04Node(data);
    
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue04::dequeue()
{
    if (isEmpty())
    {
        return;
    }
    
    Queue04Node* nextFront = front->next;
    delete front;
    front = nextFront;
    
    if (isEmpty())
    {
        rear = nullptr;
    }
}

bool Queue04::isEmpty() const
{
    return front == nullptr;
}

void Queue04::copyFrom(const Queue04& other)
{
    Queue04Node* curNode = other.front;
    while (curNode!=nullptr)
    {
        enqueue(curNode->data);
        
        curNode = curNode->next;
    }
}

void Queue04::clear()
{
    while (front != nullptr)
    {
        Queue04Node* nextFront = front->next;
        delete front;
        front = nextFront;
    }
}
