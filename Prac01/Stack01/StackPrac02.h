#pragma once

class StackNode
{
public:
    StackNode(int data, StackNode* prev);
    ~StackNode();
    int data;
    StackNode* prev;
};

class StackPrac02
{
public:
    StackPrac02();
    ~StackPrac02();

    void push(int data);
    int pop();
    int peek();

    int size;
    StackNode* top;
};
