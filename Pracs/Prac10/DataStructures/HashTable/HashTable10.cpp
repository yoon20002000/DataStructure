#include "HashTable10.h"

HashTable10::HashTable10() : table(TABLE_SIZE)
{
}

void HashTable10::insert(int key, const std::string& value)
{
    int idx = hash(key);
    for (std::pair<int, std::string>& pair : table[idx])
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }
    table[idx].emplace_back(key, value);
}

bool HashTable10::remove(int key)
{
    int idx = hash(key);
    
    for (std::list<std::pair<int,std::string>>::iterator it = table[idx].begin(); it != table[idx].end(); ++it)
    {
        if (it->first == key)
        {
            table[idx].erase(it);
            return true;
        }
    }
    
    return false;
}

std::string* HashTable10::get(int key)
{
    int idx = hash(key);
    for (std::pair<int, std::string>& pair : table[idx])
    {
        if (pair.first == key)
        {
            return &(pair.second);
        }
    }
    return nullptr;
}
