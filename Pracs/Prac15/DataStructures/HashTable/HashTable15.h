#pragma once
#include <list>
#include <optional>
#include <string>
#include <vector>

using valuePair = std::pair<std::string,int>;

class HashTable15
{
public:
    HashTable15();
    ~HashTable15() = default;
    HashTable15(const HashTable15& other);
    HashTable15& operator=(const HashTable15& other);
    HashTable15(HashTable15&& other) noexcept;
    HashTable15& operator=(HashTable15&& other) noexcept;
    
    void insert(const valuePair& pair);
    std::optional<valuePair> search(const std::string& key) const;
    void deleteVP(const std::string& key);
    
private:
    int hash(std::string key) const
    {
        int total = 0;
        int prime = 13;
        for (size_t i = 0; i < key.length(); i++)
        {
            total = total * prime + key[i];
        }
        return abs(total) % MAX_CAPACITY;
    }
    
private:
    static constexpr int MAX_CAPACITY = 10;  
    std::vector<std::list<valuePair>> table;
};
