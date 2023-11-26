#include "hash/hash.hpp"

int main() {
    try {
        // TestCases
        Hash h1, h2, h3, h4;

        h1.readDescription("UnlimitedSea_description.txt");
        //h2.readDescription("UnlimitedSea_description2.txt");
        //h3.readDescription("UnlimitedSea_description3.txt");
        //h4.readDescription("UnlimitedSea_description4.txt");

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}