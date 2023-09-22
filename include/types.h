//
// Created by Thomas Dion-Grondin on 2023-09-21.
//

#ifndef SORTING_ALGORITHMS_TYPES_H
#define SORTING_ALGORITHMS_TYPES_H

typedef void (*render_func_t) (int[], int, int);

typedef void (*sort_func_t) (render_func_t, int[], int);

typedef enum
{
  PERFORMANCE,
  RENDER,
} SORT_STRATEGY;

typedef struct
{
  char name[50];
} choice_t;

typedef struct
{
  char name[50];
  SORT_STRATEGY strategy;
} sort_choice_strategy_t;

typedef struct
{
  char name[50];
  sort_func_t sort_func;
} sort_choice_algorithm_t;

typedef struct
{
  sort_choice_algorithm_t *algorithm;
  sort_choice_strategy_t *sort_strategy;
} sort_config;

#endif // SORTING_ALGORITHMS_TYPES_H
