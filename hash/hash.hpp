#pragma once
#include <iostream>
#include <list>

class Hash {
    private:
        int SIZE;
        int currentSize;
        std::list<std::pair<std::string, int>> *table;
        int hashing(std::string key);
        void updateSize();
        bool isFull();
    public:
        Hash(int n);
        void insert(std::pair<std::string, int> data);
        int findValue(std::string key);
        void print();
};