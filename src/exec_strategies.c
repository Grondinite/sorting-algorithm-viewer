#include "../include/exec_strategies.h"
#include "../include/visualizer.h"

// Comparator for qsort
int
compare (const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

// Verify array sorting
int
verify_sorting (int original[], const int sorted[], int n)
{
  int temp[n];
  memcpy (temp, original, n * sizeof (int));
  qsort (temp, n, sizeof (int), compare);
  for (int i = 0; i < n; ++i)
    {
      if (temp[i] != sorted[i])
        {
          fprintf (stderr, "Sorting verification failed.\n");
          return -1;
        }
    }
  printf ("Sorting verified.\n");
  return 0;
}

// Measure sort function performance
void
performance_test (sort_func_t sort_func, int arr[], int n)
{
  clock_t start = clock ();
  sort_func (NULL, arr, n);
  double cpu_time_used = (double)(clock () - start) / CLOCKS_PER_SEC;
  printf ("Time taken: %f seconds\n", cpu_time_used);
}

// Execute specified sorting strategy
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
