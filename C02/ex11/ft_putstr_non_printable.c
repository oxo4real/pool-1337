/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:33 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/02 18:40:21 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_int_in_hex(unsigned char i)
{
	if (i == 0)
	{
		return ;
	}
	ft_print_int_in_hex(i / 16);
	write(1, &"0123456789abcdef"[i % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if ((unsigned char)str[i] >= 32 && (unsigned char)str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			if ((unsigned char)str[i] < 16)
			{
				write(1, "0", 1);
			}
			if ((unsigned char)str[i] != 0)
				ft_print_int_in_hex((unsigned char)str[i]);
			else
				write(1, "0", 1);
		}
		i++;
	}
}
