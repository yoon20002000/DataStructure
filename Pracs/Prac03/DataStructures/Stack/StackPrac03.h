#pragma once

class StackPrac03Node
{
public:
    StackPrac03Node();
    StackPrac03Node(int data, StackPrac03Node* prev = nullptr);
    ~StackPrac03Node();
    StackPrac03Node(const StackPrac03Node& other) = delete;
    StackPrac03Node& operator=(const StackPrac03Node& other) = delete;
    StackPrac03Node(StackPrac03Node&& other) noexcept; 
    StackPrac03Node& operator=(StackPrac03Node&& other) noexcept;
    
public:
    int data;
    StackPrac03Node* prev;
};

class StackPrac03
{
public:
    StackPrac03();
    ~StackPrac03();
    StackPrac03(const StackPrac03& other);
    StackPrac03& operator=(const StackPrac03& other);
    StackPrac03(StackPrac03&& other) noexcept;
    StackPrac03& operator=(StackPrac03&& other) noexcept;

    void push(int data);
    void pop();
    int peek() const;
    int getSize() const;
    bool isEmpty() const;
private:
    void deleteNodes();
    
private:
    StackPrac03Node* top;
    int size;
};
