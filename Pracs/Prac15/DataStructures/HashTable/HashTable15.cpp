#include "HashTable15.h"

HashTable15::HashTable15() : table(MAX_CAPACITY) 
{
    
}
void temp()
{
    int* bestPieces1[10];
    int** bestPieces = bestPieces1;

    for (int i = 0; i < 10; ++i)
    {
        bestPieces[i] = new int(i);
    }
}
HashTable15::HashTable15(const HashTable15& other) : table(other.table)
{
}

HashTable15& HashTable15::operator=(const HashTable15& other)
{
    if (&other != this)
    {
        table = other.table;
    }
    return *this;
}

HashTable15::HashTable15(HashTable15&& other) noexcept : table(std::move(other.table))
{
}

HashTable15& HashTable15::operator=(HashTable15&& other) noexcept
{
    if (&other != this)
    {
        table = std::move(other.table);
    }
    return *this;
}

void HashTable15::insert(const valuePair& pair)
{
    int index = hash(pair.first);

    for (auto& element : table[index])
    {
        if (element.first == pair.first)
        {
            element.second = pair.second;
            return;
        }
    }
    table[index].push_back(pair);
}

std::optional<valuePair> HashTable15::search(const std::string& key) const
{
    int index = hash(key);

    for (auto element : table[index])
    {
        if (element.first == key)
        {
            return element;
        }
    }
    return std::nullopt;
}

void HashTable15::deleteVP(const std::string& key)
{
    int index = hash(key);

    for (auto iter = table[index].begin(); iter != table[index].end(); ++iter)
    {
        if (iter->first == key)
        {
            table[index].erase(iter);
            return;
        }
    }
}
