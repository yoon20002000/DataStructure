#pragma once
#include <span>

class QuickSort13
{
public:
    void sort(std::span<int> arr);
    void sortMOT(std::span<int> arr);
private:
    int partitionL(std::span<int> arr, int left, int right);
    void quickSortL(std::span<int> arr, int left, int right);

    int partitionH(std::span<int> arr, int left, int right);
    void quickSortH(std::span<int> arr, int left, int right);

    void quickSortMOT(std::span<int>arr, int left, int right);
    int medianOfThree(std::span<int>arr, int left, int right);
    int partition(std::span<int> arr, int left, int right,int pivot);
};
