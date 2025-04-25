#pragma once
#include <list>
#include <string>
#include <vector>

class HashTable10
{
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::list<std::pair<int,std::string>>> table;
    inline int hash(int key) const
    {
        return key % TABLE_SIZE;
    }
public:
    HashTable10();
    void insert(int key, const std::string& value);
    bool remove(int key);
    std::string* get(int key);
};
