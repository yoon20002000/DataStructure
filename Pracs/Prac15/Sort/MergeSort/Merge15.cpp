#include "Merge15.h"

void Merge15::sort(std::span<int>& arr)
{
    std::vector<int> temp(arr.size());
    mergeSort(arr, 0, arr.size() - 1,temp);
}

void Merge15::mergeSort(std::span<int>& arr, int left, int right, std::vector<int>& temp)
{
    if (left < right)
    {
        int mid = left + (right- left) / 2;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }
}

void Merge15::merge(std::span<int>& arr, int left, int mid, int right, std::vector<int>& temp)
{
    std::copy_n(arr.begin() + left, mid - left + 1, temp.begin() + left);
    //std::copy(arr.begin() + left, arr.begin() + mid + 1, temp.begin() + left);
    std::copy_n(arr.begin() + mid + 1, right - mid + 1, temp.begin() + mid + 1);
    //std::copy(arr.begin() + mid + 1, arr.begin() + right + 1, temp.begin() + mid + 1);

    int lIndex = left;
    int rIndex = mid + 1;
    int newIndex = left;
    while (lIndex <= mid && rIndex <= right)
    {
        if (temp[lIndex]<=temp[rIndex])
        {
            arr[newIndex++] = temp[lIndex++];
        }
        else
        {
            arr[newIndex++] = temp[rIndex++];
        }
    }

    while (lIndex <= mid)
    {
        arr[newIndex++] = temp[lIndex++];
    }
    
    while (rIndex <= right)
    {
        arr[newIndex++] = temp[rIndex++];
    }
}
