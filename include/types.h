//
// Created by Thomas Dion-Grondin on 2023-09-21.
//

#ifndef SORTING_ALGORITHMS_TYPES_H
#define SORTING_ALGORITHMS_TYPES_H

typedef void (*render_func_t) (int[], int, int);

typedef void (*sort_func_t) (render_func_t, int[], int);

enum SORT_STRATEGY
{
  PERFORMANCE,
  RENDER
};

struct sort_choice_strategy
{
  char name[50];
  enum SORT_STRATEGY strategy;
};

struct sort_choice_algorithm
{
  char name[50];
  sort_func_t sort_func;
};

struct sort_config
{
  struct sort_choice_algorithm *algorithm;
  struct sort_choice_strategy *sort_strategy;
};

#endif // SORTING_ALGORITHMS_TYPES_H
