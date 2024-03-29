#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers
 * @size: size of line
 * @direction: direction to slide
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	return (slide_right(line, size));
}

/**
 * slide_left - slide an array of integers to the left
 * @line: points to an array of integers
 * @size: size of line
 * Return: 1
 */
int slide_left(int *line, size_t size)
{
	int n1 = 0, n2 = 0;
	size_t count = 0, i;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0 && n1 == 0)
			n1 = line[i];
		else if (line[i] != 0 && n1 != 0)
			n2 = line[i];
		if (n1 != 0 && n2 != 0)
		{
			if (n1 == n2)
			{
				line[count++] = n1 + n2;
				n1 = 0;
				n2 = 0;
			}
			else
			{
				line[count++] = n1;
				n1 = n2;
				n2 = 0;
				if (i == size - 1)
					line[count++] = n1;
			}
		}
		else if (n1 != n2 && i == size - 1)
			line[count++] = n1;
	}
	for (i = count; i < size; i++)
		line[i] = 0;

	return (1);
}

/**
 * slide_right - slide an array of integers to the right
 * @line: points to an array of integers
 * @size: size of line
 * Return: 1
 */
int slide_right(int *line, size_t size)
{
	int n1 = 0, n2 = 0;
	size_t count = size - 1, i;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0 && n1 == 0)
			n1 = line[i];
		else if (line[i] != 0 && n1 != 0)
			n2 = line[i];
		if (n1 != 0 && n2 != 0)
		{
			if (n1 == n2)
			{
				line[count--] = n1 + n2;
				n1 = 0;
				n2 = 0;
			}
			else
			{
				line[count--] = n1;
				n1 = n2;
				n2 = 0;
				if (i == 0)
					line[count--] = n1;
			}
		}
		else if (n1 != n2 && i == 0)
			line[count--] = n1;
	}
	for (i = 0; i < count + 1; i++)
		line[i] = 0;

	return (1);
}
