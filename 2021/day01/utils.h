#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

typedef struct {
	int * array;
	size_t size;
} Array;

Array initArray ();

void insertArray(Array * a, int element);

#endif
