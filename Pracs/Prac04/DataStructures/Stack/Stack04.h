#pragma once

class Stack04Node
{
public:
    Stack04Node();
    Stack04Node(int data, Stack04Node* prev);
    ~Stack04Node();
    Stack04Node(const Stack04Node& other) = delete;
    Stack04Node& operator=(const Stack04Node& other) = delete;
    Stack04Node(Stack04Node&& other) noexcept;
    Stack04Node& operator=(Stack04Node&& other) noexcept;

public:
    int data;
    Stack04Node* prev;
};

class Stack04
{
public:
    Stack04();
    ~Stack04();
    Stack04(const Stack04& other);
    Stack04& operator=(const Stack04& other);
    Stack04(Stack04&& other);
    Stack04& operator=(Stack04&& other);

    void push(int data);
    void pop();
    int peek() const;
    bool isEmpty() const;
private:
    void copyFrom(const Stack04& other);
    void clear();
public:
    Stack04Node* top;


    
};
