#pragma once

class StackPrac02
{
public:
    StackPrac02();
    StackPrac02(int capacity);
    ~StackPrac02();
    StackPrac02(const StackPrac02& other);
    StackPrac02& operator=(const StackPrac02& other);
    StackPrac02(StackPrac02&& other);
    StackPrac02& operator=(StackPrac02&& other);

    void push(int value);
    int pop();
    int top() const;
    bool isEmpty() const;
    void reserve(int newCapacity);

    int getCapacity() const;
    int getSize() const;
    void printStack() const;
private:
    int* stack;
    int size;
    int capacity;
};
