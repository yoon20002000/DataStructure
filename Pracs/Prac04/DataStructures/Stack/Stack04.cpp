#include "Stack04.h"

#include <vector>

Stack04Node::Stack04Node() : data(0), prev(nullptr)
{
}

Stack04Node::Stack04Node(int data, Stack04Node* prev) : data(data), prev(prev)
{
}

Stack04Node::~Stack04Node()
{
}

Stack04Node::Stack04Node(Stack04Node&& other) noexcept
{
    data = other.data;
    prev = other.prev;

    other.data = 0;
    other.prev = nullptr;
}

Stack04Node& Stack04Node::operator=(Stack04Node&& other) noexcept
{
    data = other.data;
    prev = other.prev;

    other.data = 0;
    other.prev = nullptr;

    return *this;
}

Stack04::Stack04() : top(nullptr)
{
}

Stack04::~Stack04()
{
    clear();
}

Stack04::Stack04(const Stack04& other) : top(nullptr)
{
    if (other.top == nullptr)
    {
        return;
    }

    copyFrom(other);
}

Stack04& Stack04::operator=(const Stack04& other)
{
    if (&other == this)
    {
        return *this;
    }
    
    copyFrom(other);

    return *this;
}

Stack04::Stack04(Stack04&& other) : top(other.top)
{
    other.top = nullptr;
}

Stack04& Stack04::operator=(Stack04&& other)
{
    if (&other == this)
    {
        return *this;
    }

    clear();

    top = other.top;
    other.top = nullptr;

    return *this;
}

void Stack04::push(int data)
{
    top = new Stack04Node(data, top);
}

void Stack04::pop()
{
    if (isEmpty())
    {
        return;
    }

    Stack04Node* nextTop = top->prev;
    delete top;
    top = nextTop;
}

int Stack04::peek() const
{
    if (isEmpty())
    {
        return -1;
    }

    return top->data;
}

bool Stack04::isEmpty() const
{
    return top == nullptr;
}

void Stack04::copyFrom(const Stack04& other)
{
    clear();

    std::vector<Stack04Node*> otherReverse;
    Stack04Node* curNode = other.top;
    while (curNode != nullptr)
    {
        otherReverse.push_back(curNode);
        curNode = curNode->prev;
    }

    for (int i = otherReverse.size() - 1; i >= 0; i--)
    {
        push(otherReverse[i]->data);
    }
}

void Stack04::clear()
{
    while (top != nullptr)
    {
        Stack04Node* nextTop = top->prev;
        delete top;
        top = nextTop;
    }
}
