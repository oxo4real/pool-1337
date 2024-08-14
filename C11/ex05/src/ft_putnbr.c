/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:53:30 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/09 11:43:02 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
