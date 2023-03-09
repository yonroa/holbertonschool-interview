#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
*/
void menger(int level)
{
	int x, y, i, j, z = pow(3, level);
	char p;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}

	for (i = 0; i < z; i++)
	{
		for (j = 0; j < z; j++)
		{
			x = i;
			y = j;
			p = '#';
			while (y)
			{
				if (x % 3 == 1 && y % 3 == 1)
					p = ' ';
				x /= 3;
				y /= 3;
			}
			printf("%c", p);
		}
		printf("\n");
	}
}
