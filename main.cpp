#include "hash/tabla_hash.hpp"
#include "functions/appHash.hpp"

int main() {
    try {

        // TestCase - 1
        int a[] = {50, 700, 76, 85, 73, 101, 92};
        Hash h1(7);
        Hash h2(7);

        /* TestCase - 2
        int a[] = {1, 11, 21, 31, 41, 51, 61, 71, 81, 91};
        Hash h1(10);
        Hash h2(10);

        // TestCase - 3
        int a[] = {50, 700, 76, 85, 73, 101, 92, 1};
        Hash h1(7);
        Hash h2(7);

        // TestCase - 4
        int a[] = {1, 2, 3, 4, 5};
        Hash h1(5);
        Hash h2(5);
        */

        int n = sizeof(a)/sizeof(a[0]);
        for (int i=0; i < n; ++i) {
            quadratic(h1, a[i]);
            chain(h2, a[i]);
        }

        h1.displayHash();
        h2.displayHash();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}