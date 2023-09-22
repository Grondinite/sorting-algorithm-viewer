cmake_minimum_required(VERSION 3.26)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 23)

add_executable(sorting_algorithms src/main.c
        src/bubble_sort.c
        include/utils.h
        src/utils.c
        include/sorting.h
        src/selection_sort.c
        src/visualizer.c
        include/visualizer.h
        include/constants.h
        src/exec_strategies.c
        include/exec_strategies.h
        include/types.h
)
