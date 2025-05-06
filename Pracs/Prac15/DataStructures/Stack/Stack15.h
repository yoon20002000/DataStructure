#pragma once
#include <optional>

class Stack15
{
public:
    Stack15(size_t inCapacity);
    ~Stack15();
    Stack15(const Stack15& other);
    Stack15& operator=(const Stack15& other);
    Stack15(Stack15&& other) noexcept;
    Stack15& operator=(Stack15&& other) noexcept;

    void push(int value);
    void pop();
    std::optional<int> peek() const;
    bool isEmpty() const;
    bool isFull() const;
    
private:
    void reserve(size_t inCapacity);
private:
    int* stack;
    size_t size;
    size_t capacity;
};
