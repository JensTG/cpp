#include "PNG.hpp"

#include <array>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ios>
#include <vector>
#include <cmath>
using namespace std;

int pngSignatureArray[] = {137, 80, 78, 71, 13, 10, 26, 10};

int printBasicInfo(char* filename);

int main(int argc, char** argv) {
    /*
    if (printBasicInfo(argv[1]) != 0)
        return -1;
    */

    ifstream formatStream("003_PNG_INFO.txt");
    cout << '\n' << "Furthermore:" << '\n';
    while (!formatStream.fail())
        cout << (char)formatStream.get();

    return 0;
}

int printBasicInfo(char* filename) {
    ifstream pngStream(filename, ios_base::in);

    cout << '\n' << "Checking PNG validity..." << '\n';

    for (int i = 0; i < 8 && !pngStream.eof(); i++) {
        if (pngSignatureArray[i] != pngStream.get()) {
            cout << "That is NOT a PNG" << '\n';
            return -1;
        }
    }
    cout << "Yup, that is a PNG" << '\n';

    vector<int> chunkLengths;
    vector<string> chunkNames;
    do {
        chunkLengths.push_back(bytesToInt(&pngStream, 4));

        string ph = "NULL";
        for (int i = 0; i < 4; i++)
            ph[i] = (char)pngStream.get();
        chunkNames.push_back(ph);

        pngStream.seekg((int)pngStream.tellg() + 4 + chunkLengths.back());
    } while (!pngStream.fail() && chunkNames.back() != "IEND");

    cout << '\n' << '\n' << "Type" << '\t' << "Length" << '\n';
    for (int i = 0; i < chunkLengths.size(); i++)
        cout << chunkNames[i] << '\t' << chunkLengths[i] << '\n';

    return 0;
}