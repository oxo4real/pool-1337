/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:34:30 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/17 11:21:56 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

#define BGSTROW 2
#define BGSTCOL 1
#define SIZE 0

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	min(int i1, int i2, int i3)
{
	int	min;

	min = i1;
	if (i2 < min)
		min = i2;
	if (i3 < min)
		min = i3;
	return (min);
}

void	ft_print(int **int_grid, int data[3], int height, int width)
{
	int	row;
	int	col;
	int	limitrow;
	int	limitcol;

	limitrow = data[BGSTROW] - data[SIZE];
	limitcol = data[BGSTCOL] - data[SIZE];
	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			if (int_grid[row][col] == 0)
				ft_putchar(g_obstacle);
			else if (row <= data[BGSTROW] && row > limitrow
				&& col <= data[BGSTCOL] && col > limitcol)
				ft_putchar(g_full);
			else
				ft_putchar(g_empty);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	print_grid(int **int_grid, int height, int width)
{
	int	row;
	int	col;
	int	data[3];

	data[BGSTROW] = 0;
	data[BGSTCOL] = 0;
	data[SIZE] = 1;
	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			if (data[SIZE] < int_grid[row][col])
			{
				data[SIZE] = int_grid[row][col];
				data[BGSTROW] = row;
				data[BGSTCOL] = col;
			}
			col++;
		}
		row++;
	}
	ft_print(int_grid, data, height, width);
}

void	biggest_square(int **int_grid, int height, int width)
{
	int	row;
	int	col;

	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			if ((col - 1 < 0 || row - 1 < 0) && int_grid[row][col])
				int_grid[row][col] = 1;
			else if (int_grid[row][col])
				int_grid[row][col] = min(int_grid[row - 1][col],
						int_grid[row][col - 1],
						int_grid[row - 1][col - 1]) + 1;
			col++;
		}
		row++;
	}
	print_grid(int_grid, height, width);
}
