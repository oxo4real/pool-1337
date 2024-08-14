/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:36:01 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/17 12:13:27 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int n = 10;

void	ft_putnbr(int nb)
{
	char		c;
	long long	nbr;

	nbr = (long long)nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	c = (nbr % 10) + 48;
	if (nbr / 10 != 0)
	{
		ft_putnbr(nbr / 10);
	}
	write(1, &c, 1);
}

int	ft_check(int grid[n], int col)
{
	int	row;
	int	negdiag;
	int	posdiag;

	row = grid[col];
	negdiag = row - col;
	posdiag = row + col;
	col--;
	while (col >= 0)
	{
		if (row == grid[col] || negdiag == grid[col] - col
			|| posdiag == grid[col] + col)
			return (0);
		col--;
	}
	return (1);
}

void	ft_print_solution(int grid[n])
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(grid[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_find_solution(int grid[n], int depth, int *i)
{
	int	j;

	if (depth == n && ft_check(grid, depth - 1))
	{
		ft_print_solution(grid);
		*i += 1;
		return ;
	}
	j = 0;
	while (j < n)
	{
		grid[depth] = j;
		j++;
		if (!ft_check(grid, depth))
			continue ;
		ft_find_solution(grid, depth + 1, i);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	grid[n];
	int	i;

	i = 0;
	ft_find_solution(grid, 0, &i);
	return (i);
}

int main()
{
	printf("%i", ft_ten_queens_puzzle());
}
