#include "../include/utils.h"

void
print_array (int arr[], int n)
{
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
  printf ("\n");
}

void
swap (int arr[], int i, int y)
{
  int tmp = arr[i];
  arr[i] = arr[y];
  arr[y] = tmp;
}

void
shuffle (int arr[], int n)
{
  srand (time (NULL));
  for (int i = n - 1; i > 0; i--)
    {
      int j = rand () % (i + 1);
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
}