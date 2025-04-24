#include "MergeSort09.h"

void MergeSort09::sort(int* arr, size_t size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }
    tempBuffer.resize(size);
    mergeSort(arr, 0, size - 1);
}

void MergeSort09::mergeSort(int* arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void MergeSort09::merge(int* arr, size_t left, size_t mid, size_t right)
{
    size_t leftIdx = left;
    size_t midIdx = mid + 1;
    size_t buffIdx = left;

    // 임시 버퍼에 복사
    while (leftIdx <= mid && midIdx <= right)
    {
        if (arr[leftIdx] <= arr[midIdx])
        {
            tempBuffer[buffIdx++] = arr[leftIdx++];
        }
        else
        {
            tempBuffer[buffIdx++] = arr[midIdx++];
        }
    }
    // 남아 있는 내용들 복사
    while (leftIdx <= mid)
    {
        tempBuffer[buffIdx++] = arr[leftIdx++];
    }
    while (midIdx <= right)
    {
        tempBuffer[buffIdx++] = arr[midIdx++];
    }

    for (size_t i = left; i <= right; ++i)
    {
        arr[i] = tempBuffer[i];
    }
}
