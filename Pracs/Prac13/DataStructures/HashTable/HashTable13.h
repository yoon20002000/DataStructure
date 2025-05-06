#pragma once
#include <list>
#include <optional>
#include <string>
#include <vector>

using pairType = std::pair<std::string,int>;

class HashTable13
{
public:
    HashTable13();
    void insert(const std::string& key, int value);
    bool remove(const std::string& key);
    std::optional<pairType> find(const std::string& key) const;
private:
    int hash(const std::string& key) const
    {
        int total = 0;
        int prime = 31;
        for (char c : key)
        {
            total = (total * prime + c) % MAX_SIZE;
        }
        return total;
    }
    
private:
    static constexpr int MAX_SIZE = 10;
    std::vector<std::list<pairType>> table;
};
