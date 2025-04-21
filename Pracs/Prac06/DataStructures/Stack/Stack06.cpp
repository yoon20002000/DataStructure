#include "Stack06.h"

#include <memory>

Stack06Node::Stack06Node() : data(0), prev(nullptr)
{
}

Stack06Node::Stack06Node(int data, Stack06Node* next) : data(data), prev(next)
{
}

Stack06Node::~Stack06Node()
{
}

int Stack06Node::getData() const
{
    return data;
}

void Stack06Node::setData(int inData)
{
    data = inData;
}

Stack06Node* Stack06Node::getPrevNode() const
{
    return prev;
}

void Stack06Node::setPrevNode(Stack06Node* nextNode)
{
    prev = nextNode;
}

Stack06::Stack06() : top(nullptr), size(0)
{
}

Stack06::~Stack06()
{
    deleteStack();
}

Stack06::Stack06(const Stack06& other)
{
    copyFromOther(other);
}

Stack06& Stack06::operator=(const Stack06& other)
{
    if (&other != this)
    {
        deleteStack();
        copyFromOther(other);    
    }
    
    return *this;
}

Stack06::Stack06(Stack06&& other) noexcept
{
    top = other.top;
    size = other.size;

    other.top = nullptr;
    other.size = 0;
}

Stack06& Stack06::operator=(Stack06&& other) noexcept
{
    if (&other != this)
    {
        top = other.top;
        size = other.size;

        other.top = nullptr;
        other.size = 0;
    }
    return *this;
}
Stack06& Stack06::operator=(Stack06 other) noexcept
{
    std::swap(top, other.top);
    return *this;
}
void Stack06::push(int data)
{
    top = new Stack06Node(data, top);
    ++size;
}

void Stack06::pop()
{
    if (isEmpty())
    {
        return;
    }
    Stack06Node* nextTop = top->getPrevNode();
    delete top;
    top = nextTop;
    --size;
}

int Stack06::getTop() const
{
    if (isEmpty())
    {
        return -1;
    }

    return top->getData();
}

Stack06Node* Stack06::getTopNode() const
{
    return top;
}

int Stack06::getSize() const
{
    return size;
}

bool Stack06::isEmpty() const
{
    return size == 0;
}

void Stack06::copyFromOther(const Stack06& other)
{
    Stack06Node* temp = other.getTopNode();
    Stack06 reverse;
    while (temp != nullptr)
    {
        reverse.push(temp->getData());
        temp = temp->getPrevNode();
    }
    
    while (reverse.isEmpty() != true)
    {
        push(reverse.getTop());
        reverse.pop();
    }
}

void Stack06::deleteStack()
{
    while (top != nullptr)
    {
        Stack06Node* nextTop = top->getPrevNode();
        delete top;
        top = nextTop;
    }
}
