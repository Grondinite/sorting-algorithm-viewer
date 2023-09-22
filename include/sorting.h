#ifndef SORTING_ALGORITHMS_SORTING_H
#define SORTING_ALGORITHMS_SORTING_H

#include "utils.h"

void bubble_sort (void (*render_func) (int[], int, int), int array[], int n);

void selection_sort (void (*render_func) (int[], int, int), int arr[], int n);

#endif // SORTING_ALGORITHMS_SORTING_H
