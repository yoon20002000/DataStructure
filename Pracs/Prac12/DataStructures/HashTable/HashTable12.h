#pragma once
#include <vector>
#include <list>
#include <string>
#include <optional>
using valueType = std::pair<std::string, int>;

class HashTable12
{
public:
	HashTable12();
	void insert(const std::string& key, int value);
	void deleteValue(const std::string& key);
	std::optional<valueType> get(const std::string& key) const;

private:
	int hash(const std::string& key) const
	{
		int total = 0;
		for (char c : key)
		{
			total += c;
		}
		return total % MAX_CAPACITY;
	}
private:
	static const int MAX_CAPACITY = 10;
	std::vector<std::list<valueType>> table;
};

