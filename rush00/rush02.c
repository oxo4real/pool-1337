/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:40:19 by aaghzal           #+#    #+#             */
/*   Updated: 2024/06/30 17:40:20 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(char start, char middle, char end, int width)
{
	int	i;

	if (width > 0)
	{
		ft_putchar(start);
		i = 1;
		while (i < width - 1)
		{
			ft_putchar(middle);
			i++;
		}
		if (width > 1)
		{
			ft_putchar(end);
		}
		ft_putchar('\n');
	}
	return ;
}

void	rush(int x, int y)
{
	int	i;

	if (x > 0 && y > 0)
	{
		print_line('A', 'B', 'A', x);
		i = 1;
		while (i < y - 1)
		{
			print_line('B', ' ', 'B', x);
			i++;
		}
		if (y > 1)
		{
			print_line('C', 'B', 'C', x);
		}
	}
	else if (x < 0 || y < 0)
	{
		write(2, "You must enter a positive integer\n", 34);
	}
	return ;
}
