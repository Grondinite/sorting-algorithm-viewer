#include "../include/sorting.h"

void
selection_sort (void (*render_func) (int[], int, int), int arr[], int n)
{
  for (int x = 0; x < n - 1; x++)
    {
      int low = x;
      for (int i = x; i < n; i++)
        {
          if (arr[low] > arr[i])
            {
              low = i;
            }
        }

      swap (arr, low, x);
      render_func (arr, n, 1000 * 100);
    }
}