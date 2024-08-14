/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo7awala.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 04:52:14 by marvin            #+#    #+#             */
/*   Updated: 2024/07/19 04:52:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_in_str(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int main(int ac, char *av[])
{
	int i;
	char *ptr;
	int	pos;

	if (ac == 3)
	{
		ptr = av[2];
		i = 0;
		while (av[1][i])
		{
			pos = is_in_str(av[1][i], ptr);
			if (pos >= 0)
			{
				ptr = &av[2][pos + 1];
				i++;
			}
			else {
				write(1, "0\n", 2);
				return (0);
			}
		}
		if (!av[1][i])
			write(1, "1", 1);
	}
	write(1, "\n", 1);
}
