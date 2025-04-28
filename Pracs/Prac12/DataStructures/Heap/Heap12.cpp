#include "Heap12.h"

Heap12::Heap12(Heap12&& other) noexcept
{
	heap = std::move(other.heap);
}

Heap12& Heap12::operator=(Heap12&& other) noexcept
{
	if (&other != this)
	{
		heap = std::move(other.heap);
	}

	return *this;
}

void Heap12::insert(int value)
{
	heap.push_back(value);
	heapifyUp(heap.size() - 1);
}

std::optional<int> Heap12::extractMax()
{
	if (isEmpty())
	{
		return std::nullopt;
	}

	int returnValue = heap[0];
	heap[0] = heap.back();
	heap.pop_back();
	heapifyDown(0);

	return returnValue;
}

void Heap12::heapifyUp(int index)
{
	while (index > 0 && heap[index] > heap[parent(index)])
	{
		std::swap(heap[index], heap[parent(index)]);
		index = parent(index);
	}
}

void Heap12::heapifyDown(int index)
{
	while (true)
	{
		int l = left(index);
		int r = right(index);
		int largest = index;

		if (l < heap.size() && heap[l] > heap[largest])
		{
			largest = l;
		}

		if (r<heap.size() && heap[r] > heap[largest])
		{
			largest = r;
		}

		if (largest == index)
		{
			return;
		}
		else
		{
			std::swap(heap[index], heap[largest]);
			index = largest;
		}
	}
}
