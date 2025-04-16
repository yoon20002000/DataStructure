#include "SingleLinkedListStackPrac02.h"

SingleLinkedListNodePrac02::SingleLinkedListNodePrac02(int data, SingleLinkedListNodePrac02* prev) : data(data), prev(prev)
{
}

SingleLinkedListNodePrac02::~SingleLinkedListNodePrac02()
{
}

SingleLinkedListNodePrac02::SingleLinkedListNodePrac02(SingleLinkedListNodePrac02&& other) noexcept
{
    data = other.data;
    prev = other.prev;

    other.data = 0;
    other.prev = nullptr;
}

SingleLinkedListNodePrac02& SingleLinkedListNodePrac02::operator=(SingleLinkedListNodePrac02&& other) noexcept
{
    data = other.data;
    prev = other.prev;

    other.data = 0;
    other.prev = nullptr;
    return *this;
}

SingleLinkedListStackPrac02::SingleLinkedListStackPrac02() : top(nullptr), size(0)
{
}

SingleLinkedListStackPrac02::~SingleLinkedListStackPrac02()
{
    while (top != nullptr)
    {
        SingleLinkedListNodePrac02* deleteNode = top;
        top = top->prev;
        delete deleteNode;
    }
}

SingleLinkedListStackPrac02::SingleLinkedListStackPrac02(SingleLinkedListStackPrac02&& other) noexcept
{
    size = other.size;
    top = other.top;

    other.size = 0;
    other.top = nullptr;
}

SingleLinkedListStackPrac02& SingleLinkedListStackPrac02::operator=(SingleLinkedListStackPrac02&& other) noexcept
{
    while (top != nullptr)
    {
        SingleLinkedListNodePrac02* deleteNode = top;
        top = top->prev;
        delete deleteNode;
    }
    
    size = other.size;
    top = other.top;

    other.size = 0;
    other.top = nullptr;
    return *this;
}

void SingleLinkedListStackPrac02::push(int value)
{
    SingleLinkedListNodePrac02* newNode = new SingleLinkedListNodePrac02(value, top);
    top = newNode;
    size++;
}

int SingleLinkedListStackPrac02::pop()
{
    if (isEmpty())
    {
        return -1;
    }

    SingleLinkedListNodePrac02* deleteNode = top;
    top = top->prev;
    int returnValue = deleteNode->data;
    delete deleteNode;
    size--;
    return returnValue;
}

int SingleLinkedListStackPrac02::peek() const
{
    if (isEmpty())
    {
        return -1;
    }

    return top->data;
}
