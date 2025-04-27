#pragma once
#include <list>
#include <optional>
#include <string>
#include <vector>

class HashTable11
{
public:
    HashTable11();

    void insert(const std::string& key, int value);
    bool remove(const std::string& key);
    std::optional<int> find(const std::string& key);

private:
    int hash(const std::string& key) const
    {
        int total = 0;
        for (char c : key)
        {
            total += c;
        }
        
        return  total % MAX_SIZE;
    }
    
private:
    static constexpr  int MAX_SIZE = 10;
    std::vector<std::list<std::pair<std::string, int>>> table;
};
