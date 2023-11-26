#include "hash/hash.hpp"

int main() {
    try {

        // TestCase
        int m = 7, n = 2;
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

        std::string b[] = {
            "the incumbent will administer the spending of kindergarten milk money and exercise responsibility for making change. He or she will share responsibility for the task of managing the money with the assistant whose skill and expertise shall ensure the successful spending exercise",
            "this individual must have the skill to perform a heart transplant and expertise in rocket science"
        };
        
        for (int i=0; i < m; ++i) {
            h1.insert(a[i]);
        }

        for (int i=0; i < n; ++i) {
            std::cout << h1.checkDescription(b[i]) << "\n";
        }

        h1.print();

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}