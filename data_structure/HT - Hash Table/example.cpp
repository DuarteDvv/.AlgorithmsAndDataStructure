#include <iostream>
#include <list>
#include <string>

class HashTable {
private:
    static const int hashGroups = 10;
    std::list<std::pair<std::string, std::string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(const std::string& key);
    void insert(const std::string& key, const std::string& value);
    void remove(const std::string& key);
    std::string search(const std::string& key);
    void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if(!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(const std::string& key) {
    int hash{};
    for(char character: key) {
        hash += character;
    }
    return hash % hashGroups;
}

void HashTable::insert(const std::string& key, const std::string& value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            std::cout << "[WARNING] Key exists, value replaced.\n";
            break;
        }
    }
    if(!keyExists) {
        cell.emplace_back(key, value);
    }
}

void HashTable::remove(const std::string& key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            std::cout << "[INFO] Key deleted.\n";
            break;
        }
    }
    if(!keyExists) {
        std::cout << "[WARNING] Key not found, not deleted.\n";
    }
}

std::string HashTable::search(const std::string& key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            return bItr->second;
        }
    }
    if(!keyExists) {
        std::cout << "[WARNING] Key not found.\n";
        return "";
    }
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if(table[i].size() == 0) {
            continue;
        }
        std::cout << i << ": ";
        for(auto& elem: table[i]) {
            std::cout << elem.first << ":" << elem.second << " ";
        }
        std::cout << "\n";
    }
}
