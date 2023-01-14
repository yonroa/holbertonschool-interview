#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: First sandpile
 * @grid2: Second sanpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (check_sandpile(grid1))
	{
		print_grid(grid1);
		stabilize(grid1);
	}
}

/**
 * sum_grids - sum two grids
 * @grid1: First sandpile
 * @grid2: Second sandpile
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * check_sandpile - Check if a sandpile is stable
 * @grid1: First sandpile
 * Return: 0 if is stable, 1 if is not.
 */
int check_sandpile(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				return (1);
	return (0);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: sandpile
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stabilize - Stabilize a sandpile
 * @grid1: First sandpile
 */
void stabilize(int grid1[3][3])
{
	int i, j;
	int grid2[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					grid2[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					grid2[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					grid2[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					grid2[i][j + 1] += 1;
			}
		}
	}
	sum_grids(grid1, grid2);
}
