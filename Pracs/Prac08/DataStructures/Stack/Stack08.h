#pragma once

class Stack08
{
public:
    Stack08(int inCapacity = 1);
    ~Stack08();
    Stack08(const Stack08& other);
    Stack08& operator=(const Stack08& other);
    Stack08(Stack08&& other) noexcept;
    Stack08& operator=(Stack08&& other) noexcept;

    void push(int value);
    void pop();
    int peek() const;
    bool isEmpty() const;
    int getSize() const;
    void reserve(int newCapacity);

private:
    int* data;
    int capacity;
    int size;
};
