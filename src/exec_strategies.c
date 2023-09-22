#include "../include/exec_strategies.h"
#include "../include/visualizer.h"

/**
 * Comparator function for qsort.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return The difference between the integers pointed to by a and b.
 */
int
compare (const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

/**
 * Verifies that the sorting function has correctly sorted the array.
 * @param original Original array before sorting.
 * @param sorted Array after sorting.
 * @param n Size of the arrays.
 * @return 1 if sorting is verified, -1 otherwise.
 */
int
verify_sorting (int original[], const int sorted[], int n)
{
  int temp[n];
  memcpy (temp, original, n * sizeof (int));
  qsort (temp, n, sizeof (int), compare);
  for (int i = 0; i < n; i++)
    {
      if (temp[i] != sorted[i])
        {
          return -1;
        }
    }
  printf ("Sorting verified, all good !");
  return 0;
}

/**
 * Measures the performance of the sorting function.
 * @param sort_func The sorting function to be tested.
 * @param arr Array to sort.
 * @param n Size of the array.
 */
void
performance_test (sort_func_t sort_func, int arr[], int n)
{
  clock_t start, end;
  double cpu_time_used;
  start = clock ();

  sort_func (NULL, arr, n);

  end = clock ();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf ("Time taken: %f seconds\n", cpu_time_used);
}

/**
 * Executes the sorting sort_strategy specified.
 * @param strategy The sorting sort_strategy (PERFORMANCE, RENDER).
 * @param sort_func The sorting function to use.
 * @param arr Array to sort.
 * @param n Size of the array.
 * @return 0 if sorting is verified, -1 otherwise.
 */
int
exec_sort_strategy (enum SORT_STRATEGY strategy, sort_func_t sort_func,
                    int arr[], int n)
{
  int copied_arr[n];
  memcpy (copied_arr, arr, n * sizeof (int));

  switch (strategy)
    {
    case PERFORMANCE:
      performance_test (sort_func, arr, n);
      break;
    case RENDER:
      sort_func (render, arr, n);
      break;
    }

  return verify_sorting (copied_arr, arr, n);
}
