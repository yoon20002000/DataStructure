#include "Queue05.h"

Queue05::Queue05() : queue(nullptr), front(0), rear(0),capacity(10)
{
    createQueue(capacity);
}

Queue05::Queue05(int capacity) : queue(nullptr), front(0), rear(0), capacity(capacity)
{
    createQueue(capacity);
}

Queue05::~Queue05()
{
    deleteQueue();
}

Queue05::Queue05(const Queue05& other)
{
    capacity = other.capacity;
    
    createQueue(capacity);
    for (int i = 0 ; i < capacity ; i++)
    {
        queue[i]=other.queue[i];
    }

    front = other.front;
    rear = other.rear;
}

Queue05& Queue05::operator=(const Queue05& other)
{
    if (&other != this)
    {
        deleteQueue();
        capacity = other.capacity;
        
        createQueue(capacity);
        for (int i = 0 ; i < capacity ; i++)
        {
            queue[i]=other.queue[i];
        }

        front = other.front;
        rear = other.rear;
    }
    return *this;
}

Queue05::Queue05(Queue05&& other) noexcept
{
    queue = other.queue;
    front = other.front;
    rear = other.rear;
    
    capacity = other.capacity;

    other.queue = nullptr;
    other.front = 0;
    other.rear = 0;
    
    other.capacity = 0;
}

Queue05& Queue05::operator=(Queue05&& other) noexcept
{
    if (&other != this)
    {
        deleteQueue();
        
        queue = other.queue;
        front = other.front;
        rear = other.rear;
        
        capacity = other.capacity;

        other.queue = nullptr;
        other.front = 0;
        other.rear = 0;
        other.capacity = 0;
    }
    return *this;
}

void Queue05::enqueue(int val)
{
    if (isFull())
    {
        return;
    }

    rear = (rear+1)%capacity;
    queue[rear] = val;
}

int Queue05::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }
    int returnValue = queue[front];
    front = (front + 1) % capacity;
    return returnValue;
}

bool Queue05::isEmpty() const
{
    return front == rear;
}

bool Queue05::isFull() const
{
    return (rear+1) % capacity == front;
}

int Queue05::getSize() const
{
    return (rear - front + capacity) % capacity;
}

void Queue05::createQueue(int inCapacity)
{
    if (queue != nullptr)
    {
        deleteQueue();
    }
    capacity = inCapacity + 1;
    queue = new int[capacity];
}

void Queue05::deleteQueue()
{
    delete[] queue;
}
