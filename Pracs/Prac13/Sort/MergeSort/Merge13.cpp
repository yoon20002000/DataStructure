#include "Merge13.h"

void Merge13::sort(std::span<int> arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    std::vector<int> temp(arr.size());
    mergeSort(arr, 0, arr.size() - 1, temp);
}

void Merge13::mergeSort(std::span<int> arr, int left, int right, std::vector<int>& temp)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }
}

void Merge13::merge(std::span<int> arr, int left, int mid, int right, std::vector<int>& temp)
{
    std::copy_n(arr.begin()+left, right - left + 1, temp.begin() + left);

    int l = left;
    int r = mid+1;
    int n = left;
    while (l < mid +1 && r < right + 1)
    {
        if (temp[l] <= temp[r])
        {
            arr[n++] = temp[l++];
        }
        else
        {
            arr[n++] = temp[r++];
        }
    }

    while (l < mid + 1)
    {
        arr[n++] = temp[l++];
    }
    while (r < right + 1)
    {
        arr[n++] = temp[r++];
    }
}
