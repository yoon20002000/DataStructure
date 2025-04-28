#include "HashTable12.h"

HashTable12::HashTable12() : table(MAX_CAPACITY)
{
}

void HashTable12::insert(const std::string& key, int value)
{
	int index = hash(key);
	for (auto& el : table[index])
	{
		if (el.first == key)
		{
			el.second = value;
			return;
		}
	}

	table[index].emplace_back(key, value);
}

void HashTable12::deleteValue(const std::string& key)
{
	int index = hash(key);
	// C++20 최신 기법
	std::erase_if(table[index], [&](const auto& elem) {return elem.first == key; });
	
	//for (auto iter = table[index].begin(); iter != table[index].end(); ++iter)
	//{
	//	if (iter->first == key)
	//	{
	//
	//		table[index].erase(iter);
	//		return;
	//	}
	//}
}

std::optional<valueType> HashTable12::get(const std::string& key) const
{
	int index = hash(key);

	for (auto& el : table[index])
	{
		if (el.first == key)
		{
			
			return std::optional<valueType>(el);
		}
	}
	return std::nullopt;
}
