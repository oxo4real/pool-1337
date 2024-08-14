/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:25:47 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/08 10:42:27 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_printgrid(int grid[4][4]);
int		ft_2dchecker(int grid[4][4], int trg);

int	ft_find_possible_sol_row(int row[2], int arr[24][4], int i)
{
	int	j;

	i++;
	while (i < 24)
	{
		j = 0;
		while (j < 2)
		{
			if (row[j] != arr[i][j])
				break ;
			if (j == 1 && row[j] == arr[i][j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

void	ft_put_in_grid(int grid[4][4], int arr[4], int row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		grid[row][i] = arr[i];
		i++;
	}
}

int	ft_find_solution_grid(int grid[4][4], int depth, int row_col[2][4][2], int possible_inputs[2][24][4])
{
	int			i;
	static int	solved = 0;

	if (depth == 4)
	{
		ft_printgrid(grid);
		solved = 1;
		return (1);
	}
	i = -1;
	while (ft_find_possible_sol_row(row_col[0][depth], possible_inputs[1], i) >= 0)
	{
		i = ft_find_possible_sol_row(row_col[0][depth], possible_inputs[1], i);
		ft_put_in_grid(grid, possible_inputs[0][i], depth);
		if (!ft_2dchecker(grid, depth))
			continue ;
		ft_find_solution_grid(grid, depth + 1, row_col, possible_inputs);
	}
	return (solved);
}
