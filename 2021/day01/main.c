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

  // list = [1,2,3,4,5]
  // indz = [0,1,2,3,4]      len = 5   > 1


	// iterate through array and check for increments
	for (int i = 0; i < a.size - 3; i++) {
    int window1 = a.array[i] + a.array[i + 1] + a.array[i + 2];
    int window2 = a.array[i + 1] + a.array[i + 2] + a.array[i + 3];
		if (window1 < window2) {
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
