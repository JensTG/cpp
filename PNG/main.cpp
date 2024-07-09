#include "PNG.hpp"

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <exception>
using namespace std;

int main(int argc, char** argv) {
    try {
        PNG png(argv[1]);
    } catch (exception& e) {
        cout << e.what() << '\n';
        return -1;
    }

    return 0;
}