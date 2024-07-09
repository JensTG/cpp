#ifndef PNG_FUNCS
#define PNG_FUNCS

#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <cmath>
using namespace std;

/**
 * @brief Converts little-endian bytes to ints
 **/
int bytesToInt(ifstream* is, int n);

#endif