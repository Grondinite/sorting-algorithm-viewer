#ifndef SORTING_ALGORITHMS_UTILS_H
#define SORTING_ALGORITHMS_UTILS_H

#include <printf.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#define ARRAY_LENGTH(array, type) (sizeof (array) / sizeof (type))

void print_array (int arr[], int n);

void swap (int arr[], int i, int y);

void shuffle (int arr[], int n);

#endif // SORTING_ALGORITHMS_UTILS_Hs
