#pragma once
#include <vector>

class MergeSort10
{
public:
    void sort(int*arr, size_t size);
private:
    void mergeSort(int* arr, int left, int right);
    void merge(int* arr, int left, int mid, int right);

    std::vector<int> tempVector;
};
