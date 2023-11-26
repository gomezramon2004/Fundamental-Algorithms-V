#include "hash.hpp"

// Private Methods
int Hash::hashing(std::string key) {
    int hashVal = 0; //Initial hash value
    for (int i = 0; i < key.length(); ++i) { //Summing up the ASCII values of each character
        hashVal += int(key.at(i));
    }
    return hashVal % SIZE;  //Module the hash value with the size of the hash table
}

void Hash::updateSize() {
    this->currentSize++; //Increment the current size of the hash table by one
}

bool Hash::isFull() {
    return SIZE == currentSize; //Check if the hash table is full by comparing the current size with the declared size of the hash table
}

// Public Methods
Hash::Hash() {
    this->SIZE = 0; //Initialize the size of the hash table to zero
    this->table = new std::list<std::pair<std::string, int>>[SIZE]; //Initialize the hash table to null
    this->currentSize = 0; //Initialize the current size of the hash table to zero
}

Hash::Hash(int n) {
    this->SIZE = n; //Initialize the size of the hash table
    this->table = new std::list<std::pair<std::string, int>>[SIZE]; //Initialize the hash table
    this->currentSize = 0; //Set the current size of the hash table to zero since it is empty
}

void Hash::insert(std::pair<std::string, int> data) {
    if (this->isFull()) { //Check if the hash table is full
        throw std::runtime_error("ERROR: Relocation is not possible. Hash Table is full."); //Throw an error if the hash table is full
    }

    int index = this->hashing(data.first); //Get the index of the hash table where the data will be inserted
    this->table[index].emplace_back(data); //Insert the data to the hash table
    this->updateSize(); 
}

int Hash::findValue(std::string key) {
    int index = this->hashing(key); //Get the index of the hash table where the data is located
    for (auto x : table[index]) //Traverse the list of the hash table
        if (key == x.first) //Check if the key is equal to the key of the data in the hash table
            return x.second; //Return the value 
    return 0;
}

int Hash::checkDescription(std::string description) {
    std::istringstream iss(description); //Initialize the string stream
    std::string word; //Initialize the string variable
    int totalValue = 0; //Initialize the total value of the description
    while (iss >> word) { //Traverse the string stream
        totalValue += this->findValue(word); //Add the value of the word to the total value
    }
    return totalValue; //Return the total value of the description
}

void Hash::print() {
    for (int i = 0; i < SIZE; ++i) { //Traverse the hash table
        std::cout << i; //Print the index of the hash table
        for (auto x : table[i]) //Traverse the list of the hash table
            std::cout << " --> " << x.first << " : " << x.second; //Print the key and value of the data in the hash table
        std::cout << std::endl;
    }
}

void Hash::readDescription(std::string filename) {
    std::ifstream file(filename); // Initialize the file stream
    std::string line; // Initialize the string variable
    std::string description;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) { // Traverse the file stream
        std::string word; // Initialize the string variable
        int numWords, numDescriptions, keyValue; // Initialize the integer variables
        std::pair<std::string, int> pair; // Initialize the pair variable

        std::istringstream iss(line); // Initialize the string stream
        iss >> numWords >> numDescriptions; // Get the number of words and descriptions 
        this->SIZE = numWords; // Set the size of the hash table to the number of words
        this->table = new std::list<std::pair<std::string, int>>[SIZE]; // Initialize the hash table

        for (int i = 0; i < numWords; ++i) { // Traverse the number of words
            getline(file, line); // Get the NEXT line of the file
            std::istringstream iss(line); // Initialize the string stream for the next line
            iss >> word >> keyValue; // Get the word and its value
            pair = std::make_pair(word, keyValue); // Create a pair of the word and its value
            this->insert(pair); // Insert the pair to the hash table
        }

        int i = 0;
        while (line != "." || i < numDescriptions) { // Traverse the number of descriptions
            std::getline(file, line); // Get the line of the file
            description += line + " "; // Concatenate the lines to form the description
            if (line == ".") { // Check if the line is a period
                std::cout << this->checkDescription(description) << std::endl; // Print the total value of the description

                i++; // Increment the number of descriptions checked if the description is complete
                description = ""; // Reset the description
            }
        }
    }
}