#pragma once
#include <optional>

class Stack16
{
public:
    Stack16();
    ~Stack16();
    Stack16(const Stack16& other);
    Stack16& operator=(const Stack16& other);
    Stack16(Stack16&& other) noexcept;
    Stack16& operator=(Stack16&& other) noexcept;

    void push(int value);
    void pop();
    std::optional<int> top() const;
private:
    void resize(int newCapacity);
    bool isEmpty() const
    {
        return size == 0;
    }
private:
    int* stack;
    int capacity;
    int size;
};
