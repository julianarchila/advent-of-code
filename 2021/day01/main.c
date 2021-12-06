#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Function: main
int main (int argc, char * argv[]){
	// Declare variables
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;


	Array a = initArray();
	int increments_count = 0;

	// open file input.txt
	fp = fopen("input.txt", "r");

	// check if file is open
	// if not, print error message and exit
	if (fp == NULL){
		printf("Error opening file\n");
		return 1;
	}

	// read file line by line
	while((read = getline(&line,&len, fp)) !=  -1){
		int n = atoi(line) * 2;
		insertArray(&a, n);
	}

	// iterate through array and check for increments
	for (int i = 1; i < a.size; i++) {
		if (a.array[i] > a.array[i-1]) {
			increments_count++;
		}
	}


	// print number of increments
	printf("Result: %d\n", increments_count);

	// close file
	if (fclose(fp) != 0){
		printf("Error closing file\n");
		return 1;
	}
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
