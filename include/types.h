#ifndef SORTING_ALGORITHMS_TYPES_H
#define SORTING_ALGORITHMS_TYPES_H

#define NAME_MAX_LENGTH                                                       \
  50 // Defined max length for algorithm and strategy names

typedef void (*render_func_t) (int[], int, int);
typedef void (*sort_func_t) (render_func_t, int[], int);

enum SORT_STRATEGY
{
  PERFORMANCE,
  RENDER
};

struct sort_choice_strategy
{
  char name[NAME_MAX_LENGTH];
  enum SORT_STRATEGY strategy;
};

struct sort_choice_algorithm
{
  char name[NAME_MAX_LENGTH];
  sort_func_t sort_func;
};

struct sort_config
{
  struct sort_choice_algorithm *algorithm;
  struct sort_choice_strategy *sort_strategy;
};

#endif // SORTING_ALGORITHMS_TYPES_H
