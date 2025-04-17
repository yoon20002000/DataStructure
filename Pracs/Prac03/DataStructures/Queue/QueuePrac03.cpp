#include "QueuePrac03.h"

QueuePrac03Node::QueuePrac03Node():data(0), next(nullptr)
{
    
}

QueuePrac03Node::QueuePrac03Node(int data, QueuePrac03Node* next) : data(data), next(next)
{
}

QueuePrac03Node::~QueuePrac03Node()
{
}

QueuePrac03Node::QueuePrac03Node(QueuePrac03Node&& other) noexcept
{
    data = other.data;
    next = other.next;

    other.data = 0;
    other.next = nullptr;
}

QueuePrac03Node& QueuePrac03Node::operator=(QueuePrac03Node&& other) noexcept
{
    if (&other == this)
    {
        return *this;
    }
    
    data = other.data;
    next = other.next;

    other.data = 0;
    other.next = nullptr;
    return *this;
}
QueuePrac03::QueuePrac03() : front(nullptr), rear(nullptr), size(0)
{
}

QueuePrac03::~QueuePrac03()
{
    deleteNodes();
}

QueuePrac03::QueuePrac03(const QueuePrac03& other)
{
    QueuePrac03Node* curNode = other.front;
    while (curNode != nullptr)
    {
        enqueue(curNode->data);
        curNode = curNode->next;
    }
}

QueuePrac03& QueuePrac03::operator=(const QueuePrac03& other)
{
    deleteNodes();

    size = other.size;
    QueuePrac03Node* curNode = other.front;
    while (curNode != nullptr)
    {
        enqueue(curNode->data);
        curNode = curNode->next;
    }
    return *this;
}

QueuePrac03::QueuePrac03(QueuePrac03&& other) noexcept
{
    front = other.front;
    rear = other.rear;
    size = other.size;

    other.front = nullptr;
    other.rear = nullptr;
    other.size = 0;
}

QueuePrac03& QueuePrac03::operator=(QueuePrac03&& other) noexcept
{
    if (&other == this)
    {
        return *this;
    }
    
    deleteNodes();
    front = other.front;
    rear = other.rear;
    size = other.size;

    other.front = nullptr;
    other.rear = nullptr;
    other.size = 0;
    return *this;
}

void QueuePrac03::enqueue(int data)
{
    QueuePrac03Node* newNode = new QueuePrac03Node(data);
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

void QueuePrac03::dequeue()
{
    if (isEmpty())
    {
        return;
    }
    QueuePrac03Node* deleteNode = front;
    front = front->next;
    delete deleteNode;
    size--;
}

int QueuePrac03::peek()
{
    if (isEmpty())
    {
        return -1;
    }

    return front->data;
}

int QueuePrac03::getSize() const
{
    return size;
}

bool QueuePrac03::isEmpty() const
{
    if (front == nullptr || rear == nullptr)
    {
        return true;
    }
    
    return false;
}

void QueuePrac03::deleteNodes()
{
    while (front != nullptr)
    {
        QueuePrac03Node* nextNode = front->next;
        delete front;
        front = nextNode;
    }
    front = nullptr;
    rear = nullptr;
    size = 0;
}
