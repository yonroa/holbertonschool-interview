#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t size, int index, size_t origin);
void swap(int *a, int *b);
void print_array(const int *array, size_t size);

#endif
