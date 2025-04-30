#pragma once
#include <optional>

class Stack14
{
public:
    Stack14(size_t inCapacity);
    ~Stack14();
    Stack14(const Stack14& other);
    Stack14& operator=(const Stack14& other);
    Stack14(Stack14&& other) noexcept;
    Stack14& operator=(Stack14&& other) noexcept;

    void push(int value);
    void pop();
    std::optional<int> peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void reserve(size_t inCapacity);
    
private:
    int* stack;
    size_t capacity;
    size_t size;
};
