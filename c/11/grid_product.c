#include <stdio.h>
#include <stdlib.h>

#include "../util/grids.h"

#define COORDS_LEN 4

int** read_input()
{
	FILE *grid_file = fopen("input", "r");

	if (!grid_file) {
		return NULL;
	}

	int** grid = int_grid(20, 20);

	// 20x20, each number is two chars wide
	for (int row = 0; row < 20; row++) {
		char row_buf[61]; // 60 chars and \n

		fgets(row_buf, 61, grid_file);

		int col_idx = 0;
		for (int col = 0; col < 60; col+=3) {
			char int_buf[] = {
				row_buf[col],
				row_buf[col+1],
				row_buf[col+2],
				'\0'
			};

			int result = atoi(int_buf);

			grid[row][col_idx] = result;
			col_idx++;
		}
	}

	fclose(grid_file);

	return grid;
}

int** coords_right(int r, int c)
{
	int** coords = int_grid(COORDS_LEN, 2);

	for (int i = 0; i < COORDS_LEN; i++) {
		coords[i][0] = r;
		coords[i][1] = c + i;
	}

	return coords;
}

int** coords_downright(int r, int c)
{
	int** coords = int_grid(COORDS_LEN, 2);

	for (int i = 0; i < COORDS_LEN; i++) {
		coords[i][0] = r + i;
		coords[i][1] = c + i;
	}

	return coords;
}

int** coords_down(int r, int c)
{
	int** coords = int_grid(COORDS_LEN, 2);

	for (int i = 0; i < COORDS_LEN; i++) {
		coords[i][0] = r + i;
		coords[i][1] = c;
	}

	return coords;
}

int** coords_downleft(int r, int c)
{
	int** coords = int_grid(COORDS_LEN, 2);

	for (int i = 0; i < COORDS_LEN; i++) {
		coords[i][0] = r + i;
		coords[i][1] = c - i;
	}

	return coords;
}

int valid(int** coords)
{
	for (int i = 0; i < COORDS_LEN; i++) {
		int r = coords[i][0];
		int c = coords[i][1];

		if (r < 0 || r >= 20 || c < 0 || c >= 20) {
			return 0;
		}
	}

	return 1;
}

long product(int** grid, int** coords)
{
	if (valid(coords)) {
		long prd = grid[coords[0][0]][coords[0][1]];
		for (int i = 1; i < COORDS_LEN; i++) {
			prd *= grid[coords[i][0]][coords[i][1]];
		}

		return prd;

	} else {
		return 0;
	}
}

int main()
{
	int** grid = read_input();

	long max_product = 0;

	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 20; c++) {
			int** right = coords_right(r, c);
			int** downright = coords_downright(r, c);
			int** down = coords_down(r, c);
			int** downleft = coords_downleft(r, c);

			long right_prd = product(grid, right);
			long downright_prd = product(grid, downright);
			long down_prd = product(grid, down);
			long downleft_prd = product(grid, downleft);

			if (right_prd > max_product) {
				max_product = right_prd;
			}

			if (downright_prd > max_product) {
				max_product = downright_prd;
			}

			if (down_prd > max_product) {
				max_product = down_prd;
			}

			if (downleft_prd > max_product) {
				max_product = downleft_prd;
			}


			free_int_grid(right);
			free_int_grid(downright);
			free_int_grid(down);
			free_int_grid(downleft);
		}
	}

	printf("%ld\n", max_product);

	free_int_grid(grid);
}
