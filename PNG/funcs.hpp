#ifndef PNG_FUNCS
#define PNG_FUNCS

#include "stdio.h"
#include "stdlib.h"
#include <exception>
#include <fstream>
#include <cmath>
using namespace std;

/**
 * @brief Converts little-endian bytes to ints
 **/
int bytesToInt(ifstream* is, int n);

class wrongFileTypeException : public exception {
    virtual const char* what() const throw() {
        return "Not a PNG!";
    }
};

#endif