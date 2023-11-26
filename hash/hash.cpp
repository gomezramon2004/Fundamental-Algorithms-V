#include "hash.hpp"

// Private Methods
int Hash::hashing(std::string key) {
    int hashVal = 0;
    for (int i = 0; i < key.length(); i++) {
        hashVal += int(key.at(i));
    }
    return hashVal % SIZE;
}

void Hash::updateSize() {
    this->currentSize++;
}

bool Hash::isFull() {
    return SIZE == currentSize;
}

// Public Methods
Hash::Hash(int n) {
    this->SIZE = n;
    this->table = new std::list<std::pair<std::string, int>>[SIZE];
    this->currentSize = 0;
}

void Hash::insert(std::pair<std::string, int> data) {
    if (this->isFull()) {
        throw std::runtime_error("ERROR: Relocation is not possible. Hash Table is full.");
    }

    int index = this->hashing(data.first);
    this->table[index].emplace_back(data);
    this->updateSize();
}

void Hash::print() {
    for (int i = 0; i < SIZE; i++) {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " --> " << x.first << " : " << x.second;
        std::cout << std::endl;
    }
}