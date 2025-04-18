#pragma once

class QuickSort04
{
public:
    void sort(int* arr, int left, int right);
    int partitionL(int* arr, int left, int right);
    int partitionH(int* arr, int left, int right);
    int partitionH1(int* arr, int left, int right);
    void print(int*arr, int size);
};
