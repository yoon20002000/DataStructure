#pragma once

class Stack07
{
public:
    Stack07();
    ~Stack07();
    Stack07(const Stack07& other);
    Stack07& operator=(const Stack07& other);
    Stack07(Stack07&& other) noexcept;
    Stack07& operator=(Stack07&& other) noexcept;

    void reserve(int newCapacity);
    void push(int data);
    void pop();
    int peek() const;
    bool isEmpty() const;
private:
    int* stack;
    int capacity;
    int size;
};
