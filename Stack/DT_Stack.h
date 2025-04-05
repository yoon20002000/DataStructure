#pragma once

class DT_Stack
{
public:
    DT_Stack();
    DT_Stack(int capacity);
    DT_Stack(const DT_Stack& other);
    DT_Stack(DT_Stack&& other) noexcept;
    ~DT_Stack();

    DT_Stack& operator=(const DT_Stack& other);
    DT_Stack& operator=(DT_Stack&& other) noexcept;
    
    void push(int inData);
    int pop();
    int peek() const;
    void reserve(int newCapacity);
    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }
    void printStack() const;
    
private:
    int size;
    int capacity;
    int* data; 
};
