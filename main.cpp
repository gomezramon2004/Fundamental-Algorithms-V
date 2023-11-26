#include "hash/hash.cpp"

int main() {
    try {
        // TestCase
        Hash h1;

        h1.readDescription("UnlimitedSea_description.txt");

        //checkDescription is used inside readDescription
    

        h1.print();

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}