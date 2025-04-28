#pragma once
#include <span>

class Bubble12
{
public:
	static void sort(std::span<int> arr, size_t size);
	static void advancedSort(std::span<int> arr, size_t size);
};

