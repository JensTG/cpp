#ifndef PNG_CHUNK
#define PNG_CHUNK

#include "stdio.h"
#include "stdlib.h"
#include <cstdint>
#include <vector>
#include <fstream>

#include "funcs.hpp"
using namespace std;

class Chunk {
    string type;
    unsigned int length;
    vector<unsigned char> data;
    unsigned char crc[4];

public:
    Chunk(ifstream* is) {
        length = bytesToInt(is, 4); // Get chunk data length

        // Get chunk type:
        type = "NULL";
        for (int i = 0; i < 4; i++)
            type[i] = (char)is->get();

        // Read data:
        for (int i = 0; i < length; i++)
            data.push_back((unsigned char)is->get());

        // Read CRC:
        for (int i = 0; i < 4; i++)type = "NULL";
            crc[i] = (unsigned char)is->get();
    }
}

#endif