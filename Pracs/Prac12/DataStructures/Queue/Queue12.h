#pragma once
#include <optional>
class Queue12
{
public:
	Queue12(int inCapacity = 1);
	~Queue12();
	Queue12(const Queue12& other);
	Queue12& operator=(const Queue12& other);
	Queue12(Queue12&& other) noexcept;
	Queue12& operator=(Queue12&& other) noexcept;

	void enqueue(int value);
	std::optional<int> dequeue();
	std::optional<int> peek() const;

	bool isFull() const
	{
		return (back + 1) % capacity == front;
	}
	bool isEmpty() const
	{ 
		return front == back;
	}
	int getSize() const
	{
		return (back - front + capacity) % capacity;
	}
private:
	
	int* queue;
	size_t capacity;
	int front;
	int back;
};

