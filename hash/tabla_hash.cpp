#include "tabla_hash.hpp"

Hash::Hash(int n) {
    this->BUCKET = n;
    table = new std::list<int>[BUCKET];
    currentBucket = 0;
}

std::list<int>* Hash::getTable() {
    return table;
}

bool Hash::isFull() {
    return BUCKET == currentBucket;
}

void Hash::updateCurrentBucket() {
    this->currentBucket++;
}

int Hash::hashing(int key) {
    return key % BUCKET;
}

void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " --> " << x;
        std::cout << std::endl;
    }
}