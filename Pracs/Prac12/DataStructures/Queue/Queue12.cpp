#include "Queue12.h"

Queue12::Queue12(int inCapacity) : queue(nullptr), capacity(inCapacity + 1), front(0), back(0)
{
	queue = new int[capacity];
}

Queue12::~Queue12()
{
	delete[] queue;
}

Queue12::Queue12(const Queue12& other) : queue(nullptr), capacity(other.capacity), front(other.front), back(other.back)
{
	queue = new int[capacity];
	for (size_t i = 0; i < capacity; ++i)
	{
		queue[i] = other.queue[i];
	}
}

Queue12& Queue12::operator=(const Queue12& other)
{
	if (&other != this)
	{
		delete[] queue;

		capacity = other.capacity;
		front = other.front;
		back = other.back;
		queue = new int[capacity];

		for (size_t i = 0; i < capacity; ++i)
		{
			queue[i] = other.queue[i];
		}
	}
	return *this;
}

Queue12::Queue12(Queue12&& other) noexcept : queue(other.queue), capacity(other.capacity), front(other.front), back(other.back)
{
	other.queue = nullptr;
	other.capacity = 0;
	other.front = 0;
	other.back = 0;
}

Queue12& Queue12::operator=(Queue12&& other) noexcept
{
	if (&other != this)
	{
		delete[] queue;

		queue = other.queue;
		capacity = other.capacity;
		front = other.front;
		back = other.back;

		other.queue = nullptr;
		other.capacity = 0;
		other.front = 0;
		other.back = 0;
	}
	return *this;
}

void Queue12::enqueue(int value)
{
	if (isFull())
	{
		return;
	}
	back = (back + 1) % capacity;
	queue[back] = value;
}

std::optional<int> Queue12::dequeue()
{
	if (isEmpty())
	{
		return std::nullopt;
	}
	int returnValue = queue[front];
	front = (front + 1) % capacity;
	return returnValue;
}

std::optional<int> Queue12::peek() const
{
	if (isEmpty())
	{
		return std::nullopt;
	}
	return queue[front];
}
