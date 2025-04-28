#include "Bubble12.h"

#include <memory>
#include <span>

void Bubble12::sort(std::span<int> arr, size_t size)
{
	if (arr.size() < 2)
	{
		return;
	}

	for (size_t i = 0; i < size - 1; ++i)
	{
		bool isSwapped = false;
		for (size_t j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped)
		{
			break;
		}
	}
}

void Bubble12::advancedSort(std::span<int> arr, size_t size)
{
	if (arr.size() < 2)
	{
		return;
	}

	size_t n = size;
	while (n > 0)
	{
		// 스왑이 안돼면 0
		size_t newN = 0;
		for (int i = 1; i < n; ++i)
		{
			if (arr[i - 1] > arr[i])
			{
				std::swap(arr[i], arr[i - 1]);
				// 가장 마지막 스왑 자리까지는 정렬이 된상태이니 그 뒤는 안 보기 위해 확인값 저장
				newN = i;
			}
		}
		// 스왑이 안돼면 0 받아서 종료
		n = newN;
	}
}
