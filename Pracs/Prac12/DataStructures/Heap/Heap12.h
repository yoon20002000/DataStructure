#pragma once
#include <vector>
#include <optional>
class Heap12
{
public:
	Heap12() = default;
	~Heap12() = default;
	Heap12(const Heap12& other) = default;
	Heap12& operator=(const Heap12& other) = default;
	Heap12(Heap12&& other) noexcept;
	Heap12& operator=(Heap12&& other) noexcept;

	void insert(int value);
	std::optional<int> extractMax();
	bool isEmpty()const
	{
		return heap.empty();
	}

private:
	int parent(int index) const
	{
		return (index - 1) / 2;
	}
	int left(int index) const
	{
		return index * 2 + 1;
	}
	int right(int index) const
	{
		return index * 2 + 2;
	}
	void heapifyUp(int index);
	void heapifyDown(int index);
private:
	std::vector<int> heap;
};

