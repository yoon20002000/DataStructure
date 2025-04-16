#pragma once

class QuickSortPrac02
{
public:
    void sort(int* arr, int left, int right);
    int partition(int* arr, int left, int right);
    int partitionHoare(int* arr, int left, int right);
    void print(int* arr, int size);
};
