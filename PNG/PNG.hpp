#ifndef PNG_H
#define PNG_H

#include "Chunk.hpp"
#include "funcs.hpp"
#include "stdlib.h"
#include "stdio.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class PNG {
    vector<Chunk> chunks;

public:
    PNG(string path) {
        // Open file stream:
        ifstream ps(path);

        // Check signature:
        unsigned char sig[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
        for (int i = 0; i < 8; i++)
            if (ps.get() != sig[i]) {
                throw wrongFileTypeException();
            }

        // Get chunks:
        do {
            chunks.push_back(Chunk(&ps));
        } while (chunks.back().getType() != "IEND");
    }
};

#endif