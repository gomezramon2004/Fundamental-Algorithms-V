#include "hash/hash.hpp"

int main() {
    try {

        // TestCase
        int m = 7;
        Hash h1(m);

        std::pair<std::string, int> a[] = {
            {"administer", 100000},
            {"spending", 200000},
            {"manage", 50000},
            {"responsibility", 25000},
            {"expertise", 100},
            {"skill", 50},
            {"money", 75000}
        };
        
        for (int i=0; i < m; ++i) {
            h1.insert(a[i]);
        }

        h1.print();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}