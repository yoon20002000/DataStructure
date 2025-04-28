#pragma once
#include <optional>

class Stack13
{
public:
    Stack13(size_t inCapacity = 1);
    ~Stack13();
    Stack13(const Stack13& other);
    Stack13& operator=(const Stack13& other);
    Stack13(Stack13&& other) noexcept;
    Stack13& operator=(Stack13&& other) noexcept;

    void push(int value);
    void pop();
    std::optional<int> peek() const;
    void reserve(size_t newCapacity);
    bool isEmpty() const
    {
        return size == 0;
    }
private:
    int* stack;
    size_t size;
    size_t capacity;
};
