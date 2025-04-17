#include "StackPrac03.h"

StackPrac03Node::StackPrac03Node() : data(0), prev(nullptr)
{
}

StackPrac03Node::StackPrac03Node(int data, StackPrac03Node* prev) : data(data), prev(prev)
{
}

StackPrac03Node::~StackPrac03Node()
{
}

StackPrac03Node::StackPrac03Node(StackPrac03Node&& other) noexcept
{
    data = other.data;
    prev = other.prev;

    other.data = 0;
    other.prev = nullptr;
}

StackPrac03Node& StackPrac03Node::operator=(StackPrac03Node&& other) noexcept
{
    data = other.data;
    prev = other.prev;

    other.data = 0;
    other.prev = nullptr;
}

StackPrac03::StackPrac03() : top(nullptr), size(0)
{
}

StackPrac03::~StackPrac03()
{
    deleteNodes();
}

StackPrac03::StackPrac03(const StackPrac03& other)
{
    StackPrac03Node* curNode = other.top;
    while (curNode != nullptr)
    {
        push(curNode->data);
        curNode = curNode->prev;
    }
    size = other.size;
}

StackPrac03& StackPrac03::operator=(const StackPrac03& other)
{
    deleteNodes();

    StackPrac03Node* curNode = other.top;
    while (curNode != nullptr)
    {
        push(curNode->data);
        curNode = curNode->prev;
    }

    size = other.size;
    return *this;
}

StackPrac03::StackPrac03(StackPrac03&& other) noexcept
{
    top = other.top;
    size = other.size;

    other.top = nullptr;
    other.size = 0;
}

StackPrac03& StackPrac03::operator=(StackPrac03&& other) noexcept
{
    if (&other == this)
    {
        return *this;
    }
    deleteNodes();
    top = other.top;
    size = other.size;

    other.top = nullptr;
    other.size = 0;
    return *this;
}

void StackPrac03::push(int data)
{
    top = new StackPrac03Node(data, top);
    size++;
}

void StackPrac03::pop()
{
    if (isEmpty())
    {
        return;
    }
    StackPrac03Node* prevTop = top->prev;
    delete top;
    top = prevTop;
    size--;
}

int StackPrac03::peek() const
{
    if (isEmpty())
    {
        return -1;
    }
    return top->data;
}

int StackPrac03::getSize() const
{
    return size;
}

bool StackPrac03::isEmpty() const
{
    return top == nullptr;
}

void StackPrac03::deleteNodes()
{
    while (top != nullptr)
    {
        StackPrac03Node* prevTop = top->prev;
        delete top;
        top = prevTop;
    }
}
