#ifndef SORTING_ALGORITHMS_SORTING_H
#define SORTING_ALGORITHMS_SORTING_H

#include "utils.h"

#define SORT_FUNC_DECL(name)                                                  \
  void name (void (*render_func) (int[], int, int), int arr[], int n)

SORT_FUNC_DECL (bubble_sort);
SORT_FUNC_DECL (selection_sort);
SORT_FUNC_DECL (insertion_sort);
SORT_FUNC_DECL (quick_sort_recursive_last_pivot);

#endif // SORTING_ALGORITHMS_SORTING_H
