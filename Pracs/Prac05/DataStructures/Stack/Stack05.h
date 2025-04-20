#pragma once

class Stack05
{
public:
    Stack05();
    Stack05(int newCapacity);
    ~Stack05();
    Stack05(const Stack05& other);
    Stack05& operator=(const Stack05& other);
    Stack05(Stack05&& other) noexcept;
    Stack05& operator=(Stack05&& other) noexcept;
    
    void push(int value);
    void pop();
    void clear();
    int top() const;
    bool isEmpty() const;
    void reserve(int newCapacity);
private:
    void copyStack(const Stack05& other);
    void deleteStack();
private:
    int* data;
    int size;
    int capacity;
};
