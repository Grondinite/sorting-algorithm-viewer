#include "../../include/sorting.h"

void
insertion_sort (void (*render_func) (int[], int, int), int arr[], int n)
{
  for (int i = 1; i < n; i++)
    {
      for (int y = i; y > 0; y--)
        {
          if (arr[y] < arr[y - 1])
            {
              swap (arr, y, y - 1);
              render_func (arr, n, 1000 * 100);
            }
        }
    }
}