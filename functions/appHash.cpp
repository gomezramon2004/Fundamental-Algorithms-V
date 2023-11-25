#include "appHash.hpp"

void quadratic(Hash& hashtable, int key) {
    int index = hashtable.hashing(key), i = 1;

    if (hashtable.isFull()) {
        throw std::runtime_error("ERROR: Relocation is not possible. Hash Table is full.");
    }

    if (!hashtable.getTable()[index].empty()) {
        
        while (!hashtable.getTable()[hashtable.hashing(index + i * i)].empty() && i < 100) {
            i++;
        }
        index = hashtable.hashing(index + i * i);
    }

    if (i == 100) { 
        throw std::runtime_error("ERROR: Item is probably unreachable to assign. Consequences of Secondary Clustering");
    }

    hashtable.getTable()[index].push_back(key);
    hashtable.updateCurrentBucket();
}

void chain(Hash& hashtable, int key) {
    int index = hashtable.hashing(key);
    hashtable.getTable()[index].push_back(key);
    hashtable.updateCurrentBucket();
}