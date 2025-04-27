#pragma once
#include <optional>
class Stack12
{
public:
	Stack12(size_t inCapacity = 1);
	~Stack12();
	Stack12(const Stack12& other);
	Stack12& operator=(const Stack12& other);
	Stack12(Stack12&& other) noexcept;
	Stack12& operator=(Stack12&& other) noexcept;

	void push(int value);
	void pop();
	std::optional<int> peek() const;
	void reserve(size_t inCapacity);

private:
	inline bool isEmpty() const
	{
		return size == 0;
	}
	inline bool isFull() const
	{
		return capacity == size;
	}

private:
	int* stack;
	size_t capacity;
	size_t size;
};

