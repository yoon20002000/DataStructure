#pragma once

class SingleLinkedListNodePrac02
{
public:
    SingleLinkedListNodePrac02(int data, SingleLinkedListNodePrac02* prev);
    ~SingleLinkedListNodePrac02();
    SingleLinkedListNodePrac02(const SingleLinkedListNodePrac02&) = delete;
    SingleLinkedListNodePrac02& operator=(const SingleLinkedListNodePrac02&) = delete;
    SingleLinkedListNodePrac02(SingleLinkedListNodePrac02&& other) noexcept;
    SingleLinkedListNodePrac02& operator=(SingleLinkedListNodePrac02&& other) noexcept;
    
    int data;
    SingleLinkedListNodePrac02* prev;
};

class SingleLinkedListStackPrac02
{
public:
    SingleLinkedListStackPrac02();
    ~SingleLinkedListStackPrac02();
    SingleLinkedListStackPrac02(const SingleLinkedListStackPrac02&) = delete;
    SingleLinkedListStackPrac02& operator=(const SingleLinkedListStackPrac02&) = delete;
    SingleLinkedListStackPrac02(SingleLinkedListStackPrac02&& other) noexcept;
    SingleLinkedListStackPrac02& operator=(SingleLinkedListStackPrac02&& other) noexcept;

    void push(int value);
    int pop();
    int peek() const;
    
    __forceinline bool isEmpty() const
    {
        return top == nullptr;
    }
    __forceinline int getSize() const
    {
        return size;
    }
    
    int size;
    
    SingleLinkedListNodePrac02* top;
};
