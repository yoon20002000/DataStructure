#include "HashTable13.h"

HashTable13::HashTable13() : table(MAX_SIZE)
{
    
}

void HashTable13::insert(const std::string& key, int value)
{
    int index = hash(key);
    for (valueType& element : table[index])
    {
        if (element.first == key)
        {
            element.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
}

bool HashTable13::remove(const std::string& key)
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

std::optional<valueType> HashTable13::find(const std::string& key) const
{
    int index = hash(key);
    for (const valueType& element : table[index])
    {
        if (element.first == key)
        {
            return element;
        }
    }
    return std::nullopt;
}
