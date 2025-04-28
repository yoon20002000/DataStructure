#include "Merge12.h"
#include <vector>


void Merge12::sort(std::span<int>& arr)
{
	if (arr.size() < 2)
	{
		return;
	}
	std::vector<int> temp(arr.size());
	std::span<int> tempSpan(temp.data(), temp.size());
	mergeSort(arr, 0, arr.size() - 1, tempSpan);
}

void Merge12::mergeSort(std::span<int>& arr, int left, int right, std::span<int>& temp)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid, temp);
		mergeSort(arr, mid + 1, right, temp);
		merge(arr, left, mid, right, temp);
	}
}

void Merge12::merge(std::span<int>& arr, int left, int mid, int right, std::span<int>& temp)
{
	for (int i = left; i <= right; ++i)
	{
		temp[i] = arr[i];
	}
	int l = left;
	int r = mid + 1;
	int n = left;
	while (l <= mid && r <= right)
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
	while (l <= mid)
	{
		arr[n++] = temp[l++];
	}
	while (r <= right)
	{
		arr[n++] = temp[r++];
	}
}
