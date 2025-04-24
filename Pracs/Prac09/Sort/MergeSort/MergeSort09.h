#pragma once
#include <vector>

class MergeSort09
{
public:
    void sort(int*arr, size_t size);
private:
    void mergeSort(int* arr, size_t left, size_t right);
    void merge(int* arr, size_t left, size_t mid, size_t right);
    std::vector<int> tempBuffer;
};
