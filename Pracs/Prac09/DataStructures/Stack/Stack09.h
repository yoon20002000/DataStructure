#pragma once

class Stack09
{
public:
    Stack09(int inCapacity = 1);
    ~Stack09();
    Stack09(const Stack09& other);
    Stack09& operator=(const Stack09& other);
    Stack09(Stack09&& other) noexcept;
    Stack09& operator=(Stack09&& other) noexcept;

    void push(int value);
    void pop();
    int peek() const;
    void reserve(int inCapacity);
    bool isEmpty() const;
    bool isFull() const;
    
private:
    int* stack;
    int capacity;
    int size;
};
