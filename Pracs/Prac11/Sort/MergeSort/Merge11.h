#pragma once
#include <vector>

class Merge11
{
public:
    void sort(int* arr, int size);
    
private:
    void mergeSort(int* arr, int left, int right, std::vector<int>& temp);
    void merge(int* arr, int left, int mid, int right, std::vector<int>& temp);
    
    
};
