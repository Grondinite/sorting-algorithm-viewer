#ifndef SORTING_ALGORITHMS_EXEC_STRATEGIES_H
#define SORTING_ALGORITHMS_EXEC_STRATEGIES_H

#include "types.h"
#include <assert.h>
#include <memory.h>
#include <printf.h>
#include <stdlib.h>
#include <sys/times.h>
#include <time.h>

void performance_test (sort_func_t sort_func, int arr[], int n);

int verify_sorting (int original[], const int sorted[], int n);

int exec_sort_strategy (enum SORT_STRATEGY, sort_func_t, int[], int);

#endif // SORTING_ALGORITHMS_EXEC_STRATEGIES_H
