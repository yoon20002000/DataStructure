#pragma once
#include <span>
#include <vector>

class Merge15
{
public:
    void sort(std::span<int>& arr);
private:
    void mergeSort(std::span<int>& arr, int left, int right, std::vector<int>& temp);
    void merge(std::span<int>& arr, int left, int mid, int right, std::vector<int>& temp);
};
