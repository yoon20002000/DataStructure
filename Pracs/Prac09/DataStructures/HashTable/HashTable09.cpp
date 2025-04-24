#include "HashTable09.h"

#include <iostream>

HashTable09::HashTable09(size_t size) : table(size)
{
}

void HashTable09::insert(const std::string& key, int value)
{
    size_t index = hash(key);
    for (Entry& entry : table[index])
    {
        if (entry.key == key)
        {
            entry.value = value;
            return;
        }
    }
    table[index].push_back(Entry{key, value});
}

void HashTable09::remove(const std::string& key)
{
    size_t index = hash(key);
    std::list<Entry>& chain = table[index];
    chain.remove_if([&](const Entry& entry) { return entry.key == key; });
}

std::optional<int> HashTable09::get(const std::string& key) const
{
    size_t index = hash(key);
    const std::list<Entry>& chain = table[index];
    for (const Entry& entry : chain)
    {
        if (entry.key == key)
        {
            return entry.value;
        }
    }
    return std::nullopt;
}

bool HashTable09::contains(const std::string& key) const
{
    return get(key).has_value();
}

void HashTable09::print() const
{
    for (size_t i = 0; i < table.size(); i++)
    {
        std::cout << "[" << i << "]" << '\n';
        for (const Entry& entry : table[i])
        {
            std::cout << "(" << entry.key << ":" << entry.value << ")" << '\n';
        }
        std::cout << '\n';
    }
}

size_t HashTable09::hash(const std::string& key) const
{
    std::hash<std::string> hasher;
    return hasher(key) % table.size();
}
