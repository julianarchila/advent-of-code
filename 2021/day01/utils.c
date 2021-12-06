#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int * array;
	size_t size;
} Array;

Array initArray () {
	return (Array) {
		.array = NULL,
		.size = 0
	};
}

void insertArray(Array * a, int element) {
	if (a->array == NULL) {
		a->array = (int * ) malloc(sizeof(int));
		if (a->array == NULL) {
			printf("Error: malloc failed\n");
			exit(1);
		}
		a->array[0] = element;
		a->size = 1;
		return;
	}

	a->array = (int *) realloc(a->array, (a->size + 1) * sizeof(int));
	a->array[a->size] = element;
	a->size++;
	return;
}
