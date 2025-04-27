#include "Stack12.h"
#include <iostream>
using namespace std;

Stack12::Stack12(size_t inCapacity) : stack(new int[inCapacity]), capacity(inCapacity), size(0)
{
}

Stack12::~Stack12()
{
	delete[] stack;
}

Stack12::Stack12(const Stack12& other) : stack(new int[other.capacity]), capacity(other.capacity), size(other.size)
{
	for (size_t i = 0; i < other.size; ++i)
	{
		stack[i] = other.stack[i];
	}
}

Stack12& Stack12::operator=(const Stack12& other)
{
	if (&other != this)
	{
		delete[] stack;
		stack = new int[other.capacity];
		capacity = other.capacity;
		size = other.size;

		for (size_t i = 0; i < other.size; ++i)
		{
			stack[i] = other.stack[i];
		}
	}

	return *this;
}

Stack12::Stack12(Stack12&& other) noexcept : stack(other.stack), capacity(other.capacity), size(other.size)
{
	other.stack = nullptr;
	other.capacity = 0;
	other.size = 0;
}

Stack12& Stack12::operator=(Stack12&& other) noexcept
{
	if (&other != this)
	{
		delete[] stack;

		stack = other.stack;
		capacity = other.capacity;
		size = other.size;

		other.stack = nullptr;
		other.capacity = 0;
		other.size = 0;
	}

	return *this;
}

void Stack12::push(int value)
{
	if (isFull())
	{
		int newCapacity = static_cast<int>(capacity * 1.5f);
		if (newCapacity == capacity)
		{
			++newCapacity;
		}
		reserve(newCapacity);
	}

	stack[size++] = value;
}

void Stack12::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty!" << endl;
		return;
	}

	--size;
}

std::optional<int> Stack12::peek() const
{
	if(isEmpty())
	{
		cout << "Stack is empty!" << endl;
		return nullopt;
	}

	return stack[size-1];
}

void Stack12::reserve(size_t inCapacity)
{
	if (inCapacity <= capacity)
	{
		return;
	}

	int* newStack = new int[inCapacity];
	for (size_t i = 0; i < size; ++i)
	{
		newStack[i] = stack[i];
	}
	delete[] stack;
	stack = newStack;
	capacity = inCapacity;
}

