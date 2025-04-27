#pragma once
#include <optional>

class Stack11
{
public:
    Stack11(int inCapacity = 1);
    ~Stack11();
    Stack11(const Stack11& other);
    Stack11& operator=(const Stack11& other);
    Stack11(Stack11&& other) noexcept;
    Stack11& operator=(Stack11&& other) noexcept;

    void push(int value);
    void pop();
    std::optional<int> peek() const;
    bool isEmpty() const;
    
private:
    void reserve(int inCapacity);
    
private:
    int* arr;
    int capacity;
    int size;
};
