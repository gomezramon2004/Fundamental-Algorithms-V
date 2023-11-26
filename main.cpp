#include "hash/hash.hpp"

int main() {
    try {
        // TestCase #1
        Hash h1;
        h1.readDescription("UnlimitedSea_description.txt");

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}