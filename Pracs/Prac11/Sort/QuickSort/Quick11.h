#pragma once

class Quick11
{
public:
    void sort(int* arr, int size);
private:
    void quickSortL(int* arr, int left, int right);
    void quickSortH(int* arr, int left, int right);
    int partitionL(int* arr, int left, int right);
    int partitionH(int* arr, int left, int right);
};
