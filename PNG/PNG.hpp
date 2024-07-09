#ifndef PNG
#define PNG

#include "stdlib.h"
#include "stdio.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Converts little-endian bytes to ints
 **/
int bytesToInt(ifstream* is, int n);

class Chunk {
    vector<byte> data;
    vector<string> properties;
    vector<int> rawValues;

public:
    string name;
    int length;
    Chunk(ifstream* is);
};

#endif