#include "../../include/sorting.h"

void
quick_sort_recursive_last_pivot_ (void (*render_func) (int[], int, int),
                                  int arr[], int low, int high)
{

  if (high - low < 1)
    {
      return;
    }

  int pivot = high;
  int i = low;

  while (pivot != i)
    {
      if (arr[pivot] < arr[i])
        {
          swap (arr, i, pivot - 1);
          if (render_func)
            render_func (arr, ARRAY_SIZE, 1000 * 25);
          swap (arr, pivot - 1, pivot);
          if (render_func)
            render_func (arr, ARRAY_SIZE, 1000 * 25);
          pivot--;
        }
      else
        {
          i++;
        }
    }

  quick_sort_recursive_last_pivot_ (render_func, arr, low, pivot - 1);
  quick_sort_recursive_last_pivot_ (render_func, arr, pivot + 1, high);
}

void
quick_sort_recursive_last_pivot (void (*render_func) (int[], int, int),
                                 int arr[], int n)
{
  quick_sort_recursive_last_pivot_ (render_func, arr, 0, n - 1);
}