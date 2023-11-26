#include "hash.hpp"

//-- Private Methods --//

// Hashing method. Sum the ASCII values of each character from the key, then module it with the size of the table.
int Hash::hashing(std::string key) {
    int hashVal = 0;
    for (int i = 0; i < key.length(); ++i) {
        hashVal += int(key.at(i));
    }
    return hashVal % SIZE; 
}

//Increment the current size of the table.
void Hash::updateSize() {
    this->currentSize++; 
}

// Check if the table is full.
bool Hash::isFull() {
    return SIZE == currentSize; 
}

//-- Public Methods --//

// Default Constructor
Hash::Hash() {
    this->SIZE = 0; 
    this->table = new std::list<std::pair<std::string, int>>[SIZE];
    this->currentSize = 0;
}

// Constructor with defined size
Hash::Hash(int n) {
    this->SIZE = n; 
    this->table = new std::list<std::pair<std::string, int>>[SIZE]; 
    this->currentSize = 0;
}

// Insert the pair of data using Separate Chaining Collision handling technique
void Hash::insert(std::pair<std::string, int> data) {
    if (this->isFull()) { 
        throw std::runtime_error("ERROR: Relocation is not possible. Hash Table is full.");
    }

    int index = this->hashing(data.first);
    this->table[index].emplace_back(data);
    this->updateSize(); 
}

// Find a value in the table by its key
int Hash::findValue(std::string key) {
    int index = this->hashing(key); 
    for (auto x : table[index]) 
        if (key == x.first) 
            return x.second; 
    return 0;
}

// Traverse the description to return the total value 
int Hash::checkDescription(std::string description) {
    std::istringstream iss(description); 
    std::string word; 
    int totalValue = 0; 
    while (iss >> word) { 
        totalValue += this->findValue(word);
    }
    return totalValue; 
}

// Print the content of the table
void Hash::print() {
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i; 
        for (auto x : table[i]) 
            std::cout << " --> " << x.first << " : " << x.second; 
        std::cout << std::endl;
    }
}

// Create an input stream to read the description file and use it to check the total value of each text.
void Hash::readDescription(std::string filename) {
    std::ifstream file(filename); 
    std::string line;
    std::string description;

    if (!file.is_open()) {
        throw std::runtime_error("ERROR: Failed to open the file.");
    }

    while (std::getline(file, line)) { // Traverse the file stream
        std::string word; 
        int numWords, numDescriptions, keyValue; 
        std::pair<std::string, int> pair; //

        std::istringstream iss(line);
        iss >> numWords >> numDescriptions; 

        if (numWords == 0 && numDescriptions == 0) {
            throw std::runtime_error("ERROR: Null inputs are provided");
        }

        this->SIZE = numWords;
        this->table = new std::list<std::pair<std::string, int>>[SIZE]; 

        for (int i = 0; i < numWords; ++i) { // Traverse the number of words
            getline(file, line);
            std::istringstream iss(line); 
            iss >> word >> keyValue; 
            pair = std::make_pair(word, keyValue); 
            this->insert(pair);
        }

        int i = 0;
        while (line != "." || i < numDescriptions) { // Traverse the number of descriptions
            std::getline(file, line); 
            description += line + " "; 
            if (line == ".") { 
                std::cout << this->checkDescription(description) << std::endl;
                i++; 
                description = ""; 
            }
        }
    }
}