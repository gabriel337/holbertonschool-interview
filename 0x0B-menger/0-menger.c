#include "menger.h"

/**
 * find_char - selects block or no block
 *
 * @col: column
 * @row: row
 * Return: '#' or ' '
 */
char find_char(int col, int row)
{
	for (; col && row; col /= 3, row /= 3)
	{
		if (col % 3 == 1 && row % 3 == 1)
			return (' ');
	}
	return ('#');
}

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	int col, row, size;

	if (level >= 0)
	{
		size = pow(3, level);
		for (col = 0; col < size; col++)
		{
			for (row = 0; row < size; row++)
				printf("%c", find_char(col, row));
			printf("\n");
		}
	}
}
