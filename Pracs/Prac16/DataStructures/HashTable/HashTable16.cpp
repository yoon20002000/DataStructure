#include "HashTable16.h"

HashTable16::HashTable16() : table(MAX_SIZE)
{
}

void HashTable16::insert(const std::string& key, const std::string& value)
{
    int index = hash(key);
    for (pairType& element : table[index])
    {
        if (element.first == key)
        {
            element.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
}

void HashTable16::remove(const std::string& key)
{
    int index = hash(key);
    // 유일한 값일 경우
    for (auto iter = table[index].begin(); iter != table[index].end(); ++iter)
    {
        if (iter->first == key)
        {
            table[index].erase(iter);
            return ;
        }
    }
    
    // 같은 값이 여러개 일 경우

    // for (auto iter = table[index].begin(); iter != table[index].end(); )
    // {
    //     if (iter->first == key)
    //     {
    //         iter = table[index].erase(iter);
    //     }
    //     else
    //     {
    //         ++iter;
    //     }
    // }
    
    // table[index].remove_if([&key](const pairType& element)
    // {
    //     return element.first == key;
    // });

    // std::erase_if(table[index],[&key](const pairType& element)
    // {
    //     return element.first == key;
    // });
}

std::optional<pairType> HashTable16::find(const std::string& key)
{
    int index = hash(key);
    for (pairType& element : table[index])
    {
        if (element.first == key)
        {
            return element;
        }
    }
    return std::nullopt ;
}

int HashTable16::hash(const std::string& key) const
{
    int total = 0;
    int prime = 31;
    for (char c : key)
    {
        total = (total * prime + c) % MAX_SIZE;
    }
    return total;
}
