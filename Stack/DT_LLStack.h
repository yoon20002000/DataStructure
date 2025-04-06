#pragma once
#include <iostream>

template <typename T>
class LLStackNode
{
public:
    LLStackNode() : data(0), prev(nullptr)
    {
        
    }
    LLStackNode(T data, LLStackNode* prev) : data(data), prev(prev)
    {
        
    }
    
public:
    T data;
    LLStackNode* prev;
};
template <typename T>
class DT_LLStack
{
public:
    DT_LLStack() : top(nullptr)
    {
        
    }
    DT_LLStack(T data, LLStackNode<T>* prev = nullptr) 
    {
        top = new LLStackNode<T>(data, prev);
    }
    DT_LLStack(DT_LLStack&& other) noexcept
    {
        top = other.top;
        other.top = nullptr;
    }
    DT_LLStack(const DT_LLStack<T>&) = delete;
    DT_LLStack<T>& operator=(const DT_LLStack<T>&) = delete;
    ~DT_LLStack()
    {
        while (top != nullptr)
        {
            LLStackNode<T>* deleteNode = top;
            top = top->prev;
            delete deleteNode;
        }
    }
    DT_LLStack<T>& operator=(DT_LLStack<T>&& other) noexcept
    {
        top = other.top;
        other.top = nullptr;
        return *this;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }
    void push(T data)
    {
        top = new LLStackNode<T>(data, top);
    }
    T pop()
    {
        if (top == nullptr)
        {
            return -1;
        }

        T returnValue = top->data;
        LLStackNode<T>* nextTop = top->prev;
        delete top;
        top = nextTop;
        return returnValue;
    }
    T peek() const
    {
        return top == nullptr ? -1 : top->data;
    }
    void printStack() const
    {
        if (top == nullptr)
        {
            return;
        }

        LLStackNode<T>* tempTop = top;
        while (tempTop !=nullptr)
        {
            std::cout<<tempTop->data<< '\n';
            tempTop = tempTop->prev;
        }
    }
private:
    LLStackNode<T>* top;
};
