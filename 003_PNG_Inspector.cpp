#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ios>
using namespace std;

int main(int argc, char** argv) {
    fstream pngStream(argv[1], ios_base::in);
    char next;
    while(pngStream >> next) {
        cout << next << '\n';
    }
    return 0;
}
