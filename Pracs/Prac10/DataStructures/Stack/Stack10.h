#pragma once
#include <optional>

class Stack10
{
public:
    Stack10(int inCapacity = 10);
    ~Stack10();
    Stack10(const Stack10& other);
    Stack10& operator=(const Stack10& other);
    Stack10(Stack10&& other) noexcept;
    Stack10& operator=(Stack10&& other) noexcept;

    void push(int value);
    void pop();
    std::optional<int> peek() const;
    bool isEmpty() const;
    bool isFull() const;

    void reserve(int inCapacity);
private:
    int* arr;
    int size;
    int capacity;
};
