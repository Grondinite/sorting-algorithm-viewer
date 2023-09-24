
#include "../../include/sorting.h"

void
bubble_sort (void (*render_func) (int[], int, int), int array[], int n)
{

  int tmp;
  for (int i = 0; i < n; i++)
    {
      for (int y = 0; y < n - i - 1; y++)
        {
          if (array[y] > array[y + 1])
            {
              tmp = array[y];
              array[y] = array[y + 1];
              array[y + 1] = tmp;
            }

          if (render_func != NULL)
            {
              render_func (array, n, 1000 * 4);
            }
        }
    }
}