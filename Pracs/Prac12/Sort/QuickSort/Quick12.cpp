#include "Quick12.h"
#include <memory>

void Quick12::sort(std::span<int>& arr)
{
	quickSortL(arr, 0, arr.size() - 1);
}

void Quick12::quickSortL(std::span<int>& arr, int left, int right)
{
	if (left < right)
	{
		int pivot = partitionL(arr, left, right);
		quickSortL(arr, left, pivot - 1);
		quickSortL(arr, pivot + 1, right);
	}
}

int Quick12::partitionL(std::span<int>& arr, int left, int right)
{
	int pivotIndex = left;
	int pivotItem = arr[pivotIndex];

	for (int i = left + 1; i <= right; ++i)
	{
		if (pivotItem > arr[i])
		{
			pivotIndex++;
			std::swap(arr[pivotIndex], arr[i]);
		}
	}
	std::swap(arr[pivotIndex], arr[left]);

	return pivotIndex;
}

void Quick12::quickSortH(std::span<int>& arr, int left, int right)
{
	if (left < right)
	{
		int pivot = partitionH(arr, left, right);
		quickSortH(arr, left, pivot);
		quickSortH(arr, pivot + 1, right);
	}
}

int Quick12::partitionH(std::span<int>& arr, int left, int right)
{
	while (true)
	{
		int l = left - 1;
		int r = right + 1;
		int midItem = arr[left + (right - left) / 2];
		do
		{
			l++;
		} while (arr[l] < midItem);

		do
		{
			r--;
		} while (arr[r] > midItem);

		if (l < r)
		{
			std::swap(arr[l], arr[r]);
		}
		else
		{
			return r;
		}
	}
}
