#pragma once

class QuickSort03
{
public:
    void sort(int* arr, int left,int right);
    int partitionL(int* arr, int left, int right);
    int partitionH(int* arr, int left, int right);
};
