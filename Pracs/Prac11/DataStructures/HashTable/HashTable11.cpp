#include "HashTable11.h"

#include <utility>

HashTable11::HashTable11()
{
    table.resize(MAX_SIZE);
}

void HashTable11::insert(const std::string& key, int value)
{
    int index = hash(key);
    for (auto& element : table[index])
    {
        if (element.first == key)
        {
            element.second = value;
            return;
        }
    }
    
    table[index].emplace_back(key, value);
}

bool HashTable11::remove(const std::string& key)
{
    int index = hash(key);
    for (auto iter = table[index].begin(); iter != table[index].end(); ++iter)
    {
        if (iter->first == key)
        {
            table[index].erase(iter);
            return true;
        }
    }
    return false;
}

std::optional<int> HashTable11::find(const std::string& key)
{
    int index = hash(key);
    for (const auto& element : table[index])
    {
        if (element.first == key)
        {
            return element.second;
        }
    }
    return std::nullopt;
}
