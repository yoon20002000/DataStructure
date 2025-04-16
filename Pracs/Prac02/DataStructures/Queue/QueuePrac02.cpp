#include "QueuePrac02.h"

#include <iterator>

LinkedListQueueNodePrac02::LinkedListQueueNodePrac02(int data, LinkedListQueueNodePrac02* prev, LinkedListQueueNodePrac02* next)
    : data(data), prev(prev), next(next)
{
}

LinkedListQueueNodePrac02::~LinkedListQueueNodePrac02()
{
}

LinkedListQueueNodePrac02::LinkedListQueueNodePrac02(LinkedListQueueNodePrac02&& other) noexcept
{
    data = other.data;
    prev = other.prev;
    next = other.next;
    
    other.data = 0;
    other.prev = nullptr;
    other.next = nullptr;
}

LinkedListQueueNodePrac02& LinkedListQueueNodePrac02::operator=(LinkedListQueueNodePrac02&& other) noexcept
{
    data = other.data;
    prev = other.prev;
    next = other.next;
    
    other.data = 0;
    other.prev = nullptr;
    other.next = nullptr;
    return *this;
}
QueuePrac02::QueuePrac02() : front(nullptr), rear(nullptr), size(0)
{
}

QueuePrac02::~QueuePrac02()
{
    while (rear != nullptr)
    {
        LinkedListQueueNodePrac02* deleteNode = rear;
        rear = rear->prev;
        delete deleteNode;
    }
}

QueuePrac02::QueuePrac02(const QueuePrac02& other)
{
    if (other.isEmpty() == false)
    {
        LinkedListQueueNodePrac02* otherFront = other.front;
        while (otherFront != nullptr)
        {
            enqueue(otherFront->data);
            otherFront = otherFront->prev;
        }   
    }
}

QueuePrac02& QueuePrac02::operator=(const QueuePrac02& other)
{
    while (rear != nullptr)
    {
        LinkedListQueueNodePrac02* deleteNode = rear;
        rear = rear->prev;
        delete deleteNode;
    }
    front = nullptr;
    rear = nullptr;
    
    if (other.isEmpty() == false)
    {
        LinkedListQueueNodePrac02* otherFront = other.front;
        while (otherFront != nullptr)
        {
            enqueue(otherFront->data);
            otherFront = otherFront->prev;
        }
    }

    return *this;
}

QueuePrac02::QueuePrac02(QueuePrac02&& other) noexcept
{
    front = other.front;
    rear = other.rear;
    size = other.size;

    other.front = nullptr;
    other.rear = nullptr;
    other.size = 0;
}

QueuePrac02& QueuePrac02::operator=(QueuePrac02&& other) noexcept
{
    while (rear != nullptr)
    {
        LinkedListQueueNodePrac02* deleteNode = rear;
        rear = rear->prev;
        delete deleteNode;
    }
    
    front = other.front;
    rear = other.rear;
    size = other.size;

    other.front = nullptr;
    other.rear = nullptr;
    other.size = 0;
    return *this;
}

int QueuePrac02::frontData() const
{
    if (isEmpty())
    {
        return -1;
    }
    return front->data;
}

int QueuePrac02::backData() const
{
    if (isEmpty())
    {
        return -1;
    }
    return rear->data;
}

void QueuePrac02::enqueue(int data)
{
    LinkedListQueueNodePrac02* newNode = new LinkedListQueueNodePrac02(data, rear, nullptr);

    if (isEmpty())
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
    }
    rear = newNode;
    ++size;
}

int QueuePrac02::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }
    LinkedListQueueNodePrac02* deleteNode = front;
    int returnValue = deleteNode->data;
    front = front->next;
    delete deleteNode;
    --size;
    return returnValue;
}

bool QueuePrac02::isEmpty() const
{
    return size == 0;
}
