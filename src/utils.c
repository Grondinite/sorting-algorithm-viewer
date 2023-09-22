#include "../include/utils.h"
#include <sys/time.h>
#include <time.h>

/**
 * Prints an array of integers.
 * @param arr The array to print.
 * @param n Size of the array.
 */
void
print_array (int arr[], int n)
{
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
  printf ("\n");
}

/**
 * Swaps the elements at indices i and y in an integer array.
 * @param arr The array containing the elements to swap.
 * @param i Index of the first element to swap.
 * @param y Index of the second element to swap.
 */
void
swap (int arr[], int i, int y)
{
  int tmp = arr[i];
  arr[i] = arr[y];
  arr[y] = tmp;
}

/**
 * Shuffles an array of integers using the Fisher-Yates algorithm.
 * @param arr The array to shuffle.
 * @param n Size of the array.
 */
void
shuffle (int arr[], int n)
{
  struct timeval tv;
  gettimeofday (&tv, NULL);
  srand (
      tv.tv_usec); // Use microsecond part of the current time for better seed

  for (int i = n - 1; i > 0; i--)
    {
      int j = rand () % (i + 1);
      swap (arr, i, j);
    }
}
