#ifndef _GRIDS_H
#define _GRIDS_H

// Is there a type-agnostic way to do this?

int** int_grid(int rows, int cols);
void free_int_grid(int** grid);

#endif // !_GRIDS_H
