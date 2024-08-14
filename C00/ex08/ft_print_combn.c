/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:45:07 by aaghzal           #+#    #+#             */
/*   Updated: 2024/06/27 17:45:07 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* the first loop is for incrementing and the second is for correction */
void	ft_increment_str(int n, char str[])
{
	int		it;

	it = n;
	str[it - 1]++;
	while (it - 1 > 0)
	{
		if (str[it - 1] > 9 - (n - it) + 48)
		{
			str[it - 2]++;
			str[it - 1] = str[it - 2] + 1;
		}
		it--;
	}
	while (it < n + 1)
	{
		if (str[it - 1] > 9 - (n - it) + 48)
		{
			str[it - 1] = str[it - 2] + 1;
		}
		it++;
	}
}

void	ft_write_str(int n, char str[])
{
	if (str[0] != 9 - (n - 1) + 48)
	{
		write(1, str, n + 2);
	}
	else 
	{
		write(1, str, n);
	}
}

void	ft_print_combn(int n)
{
	char	str[11];
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		str[i] = i + 48;
		i++;
	}
	str[n + 1] = ' ';
	str[n] = ',';
	j = 0;
	write(1, str, n + 2);
	while (str[0] != 9 - (n - 1) + 48)
	{
		ft_increment_str(n, str);
		ft_write_str(n, str);
	}
}
