#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "../include/constants.h"
#include "../include/exec_strategies.h"
#include "../include/sorting.h"

int
main (int argc, char *argv[])
{
  struct timeval tv;
  gettimeofday (&tv, NULL);

  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <sorting_algorithm> <sort_strategy>\n",
               argv[0]);
      fprintf (stderr, "Available sorting algorithms: bubble_sort, "
                       "selection_sort, insertion_sort\n");
      fprintf (stderr, "Available sort strategies: performance, render\n");
      exit (EXIT_FAILURE);
    }

  struct sort_choice_algorithm sort_algorithms[]
      = { { .name = "bubble_sort", .sort_func = bubble_sort },
          { .name = "selection_sort", .sort_func = selection_sort },
          { .name = "insertion_sort", .sort_func = insertion_sort },
          { .name = "quick_sort_recursive_last_pivot",
            .sort_func = quick_sort_recursive_last_pivot } };

  struct sort_choice_strategy strategies[]
      = { { .name = "performance", .strategy = PERFORMANCE },
          { .name = "render", .strategy = RENDER } };

  struct sort_config config = { .algorithm = NULL, .sort_strategy = NULL };

  for (int i = 0;
       i < ARRAY_LENGTH (sort_algorithms, struct sort_choice_algorithm); ++i)
    {
      if (strcmp (argv[1], sort_algorithms[i].name) == 0)
        {
          config.algorithm = &sort_algorithms[i];
          break;
        }
    }

  if (config.algorithm == NULL)
    {
      fprintf (stderr, "Error: '%s' is not a recognized sorting algorithm.\n",
               argv[1]);
      fprintf (stderr, "Available sorting algorithms: bubble_sort, "
                       "selection_sort, insertion_sort\n");
      exit (EXIT_FAILURE);
    }

  for (int i = 0; i < ARRAY_LENGTH (strategies, struct sort_choice_strategy);
       ++i)
    {
      if (strcmp (argv[2], strategies[i].name) == 0)
        {
          config.sort_strategy = &strategies[i];
          break;
        }
    }

  if (config.sort_strategy == NULL)
    {
      fprintf (stderr, "Error: '%s' is not a recognized sort strategy.\n",
               argv[2]);
      fprintf (stderr, "Available sort strategies: performance, render\n");
      exit (EXIT_FAILURE);
    }

  srand (tv.tv_usec);

  int n = ARRAY_SIZE;
  int arr[n];

  for (int i = 0; i < n; ++i)
    {
      arr[i] = i;
    }

  shuffle (arr, n);

  if (exec_sort_strategy (config.sort_strategy->strategy,
                          config.algorithm->sort_func, arr, n)
      != 0)
    {
      fprintf (stderr, "An error occurred: The sorted array is incorrect\n");
      exit (EXIT_FAILURE);
    }

  printf ("\nAlgorithm: %s\n", config.algorithm->name);
  printf ("Strategy: %s\n", config.sort_strategy->name);

  return 0;
}
