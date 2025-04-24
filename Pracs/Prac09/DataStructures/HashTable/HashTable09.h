#pragma once
#include <string>
#include <vector>
#include <list>
#include <optional>

class HashTable09
{
public:
    HashTable09(size_t size = 101);
    ~HashTable09() = default;

    void insert(const std::string& key, int value);
    void remove(const std::string& key);
    std::optional<int> get(const std::string& key) const;
    bool contains(const std::string& key) const;

    void print() const;
private:
    struct Entry
    {
        std::string key;
        int value;
    };

    std::vector<std::list<Entry>> table;
    size_t hash(const std::string& key) const;
};
