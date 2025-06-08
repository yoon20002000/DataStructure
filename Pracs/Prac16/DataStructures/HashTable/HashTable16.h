#pragma once
#include <list>
#include <optional>
#include <string>
#include <vector>

using pairType = std::pair<std::string, std::string>;

class HashTable16
{
public:
    HashTable16();
    void insert(const std::string& key, const std::string& value);
    void remove(const std::string& key);
    std::optional<pairType> find(const std::string& key);
private:
    int hash(const std::string& key) const;
private:
    static constexpr int MAX_SIZE = 10;
    std::vector<std::list<pairType>> table;
};
