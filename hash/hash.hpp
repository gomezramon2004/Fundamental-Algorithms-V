#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
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
        Hash();
        Hash(int n);
        void insert(std::pair<std::string, int> data);
        int findValue(std::string key);
        void readDescription(std::string filename);
        int checkDescription(std::string description);
        void print();
};