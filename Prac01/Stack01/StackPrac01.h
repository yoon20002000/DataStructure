#pragma once

class StackPrac01
{
public:

    StackPrac01(int newCapacity);
    ~StackPrac01();
    void reserve(int newCapacity);
    void push(int newData);
    int pop();
    int capacity;
    int size;
    int* datas;
};
