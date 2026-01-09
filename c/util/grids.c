#include "grids.h"
#include <stdlib.h>

int** int_grid(int m, int n)
{
	int ** arr = malloc(m * sizeof(int *));

	arr[0] = malloc(m * n * sizeof(int));
	for(int i = 1; i < m; i++) {
	    arr[i] = arr[0] + i * n;
	}

	return arr;
}

void free_int_grid(int** grid)
{
	free(grid[0]);
	free(grid);
}
