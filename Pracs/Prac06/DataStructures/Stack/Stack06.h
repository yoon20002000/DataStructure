#pragma once

class Stack06Node
{
public:
    Stack06Node();
    Stack06Node(int data, Stack06Node* next);
    ~Stack06Node();
    Stack06Node(const Stack06Node&) = delete;
    Stack06Node& operator=(const Stack06Node&) = delete;
    Stack06Node(Stack06Node&& other) = delete;
    Stack06Node& operator=(Stack06Node&& other) = delete;

    int getData() const;
    void setData(int inData);
    
    Stack06Node* getPrevNode() const;
    void setPrevNode(Stack06Node* nextNode);
    
private:
    int data;
    Stack06Node* prev;
};

class Stack06
{
public:
    Stack06();
    ~Stack06();
    Stack06(const Stack06& other);
    Stack06& operator=(const Stack06& other);
    Stack06(Stack06&& other) noexcept;
    Stack06& operator=(Stack06&& other) noexcept;
    // test 용
    Stack06& operator=(Stack06 other) noexcept;

    void push(int data);
    void pop();
    int getTop() const;
    Stack06Node* getTopNode() const;
    int getSize() const;
    bool isEmpty() const;
private:
    void copyFromOther(const Stack06& other);
    void deleteStack();
private:
    Stack06Node* top;
    int size;
};
