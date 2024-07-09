#include "funcs.hpp"

/**
 * @brief Converts little-endian bytes to ints
 **/
int bytesToInt(ifstream* is, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += is-> get() * pow(256, n - 1 - i);
    return sum;
}