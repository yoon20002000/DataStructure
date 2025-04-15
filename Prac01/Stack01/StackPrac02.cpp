#include "StackPrac02.h"

StackNode::StackNode(int data, StackNode* prev) : data(data), prev(prev)
{
}

StackNode::~StackNode()
{
    
}

StackPrac02::StackPrac02() : top(nullptr), size(0)
{
}

StackPrac02::~StackPrac02()
{
    if (top != nullptr)
    {
        while (top != nullptr)
        {
            StackNode* deleteNode = top;
            top = top->prev;
            delete deleteNode;
        }
    }
}

void StackPrac02::push(int data)
{
    StackNode* newNode = new StackNode(data, top);
    top = newNode;
    size++;
}

int StackPrac02::pop()
{
    if (top == nullptr)
    {
        return -1;
    }
    
    StackNode* deleteNode = top;
    int returnData = deleteNode->data;
    top = top->prev;
    delete deleteNode;
    size--;
    return returnData;
}

int StackPrac02::peek()
{
    if (top == nullptr)
    {
        return -1;
    }
    
    return top->data;
}
