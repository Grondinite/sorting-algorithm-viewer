#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/constants.h"
#include "../include/exec_strategies.h"
#include "../include/sorting.h"

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <sorting_algorithm> <sort_strategy>\n",
               argv[0]);
      exit (EXIT_FAILURE);
    }

  sort_choice_algorithm_t sort_algorithms[]
      = { { .name = "bubble_sort", .sort_func = bubble_sort },
          { .name = "selection_sort", .sort_func = selection_sort },
          { .name = "insertion_sort", .sort_func = insertion_sort } };

  sort_choice_strategy_t strategies[]
      = { { .name = "performance", .strategy = PERFORMANCE },
          { .name = "render", .strategy = RENDER } };

  sort_config config;

  for (int i = 0;
       i < sizeof (sort_algorithms) / sizeof (sort_choice_algorithm_t); i++)
    {
      if (strcmp (argv[1], sort_algorithms[i].name) == 0)
        {
          config.algorithm = &sort_algorithms[i];
        }
    }

  if (config.algorithm == NULL)
    {
      fprintf (stderr,
               "An error occurred: Option %s not recognized as a sorting "
               "algorithm\n",
               argv[1]);
      exit (EXIT_FAILURE);
    }

  for (int i = 0; i < sizeof (strategies) / sizeof (sort_choice_strategy_t);
       i++)
    {
      if (strcmp (argv[2], strategies[i].name) == 0)
        {
          config.sort_strategy = &strategies[i];
        }
    }

  if (config.sort_strategy == NULL)
    {
      fprintf (
          stderr,
          "An error occurred: Option %s not recognized as a sort_strategy\n",
          argv[2]);
      exit (EXIT_FAILURE);
    }

  // nsec
  srand (time (NULL));

  int n = ARRAY_SIZE;
  int arr[n];

  for (int i = 0; i < n; i++)
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
