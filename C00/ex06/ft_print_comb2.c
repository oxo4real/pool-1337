/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:15:13 by aaghzal           #+#    #+#             */
/*   Updated: 2024/06/27 13:15:13 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_n00(int n)
{
	char	c;
	char	cc;

	if (n <= 9)
	{
		c = n + 48;
		write(1, "0", 1);
		write(1, &c, 1);
	}
	else
	{
		c = (n / 10) + 48;
		cc = (n % 10) + 48;
		write(1, &c, 1);
		write(1, &cc, 1);
	}
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_n00(i);
			write(1, " ", 1);
			ft_print_n00(j);
			if (i < 98 || j < 99)
			{
				write(1, ", ", 2); 
			}
			j++;
		}
		i++;
	}
}
