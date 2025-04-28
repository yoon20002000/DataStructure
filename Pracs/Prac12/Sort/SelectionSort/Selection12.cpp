#include "Selection12.h"
#include <memory>
void Selection12::sort(std::span<int>& arr)
{
	if (arr.size() < 2)
	{
		return;
	}

	for (size_t i = 0; i < arr.size() - 1; ++i)
	{
		int minIndex = i;
		for (size_t j = i + 1; j < arr.size(); ++j)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(arr[minIndex], arr[i]);
		}
	}
}
