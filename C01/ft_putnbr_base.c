/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:46:31 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/08 12:48:09 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_basecheck(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i + 1] != 0)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0); 
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char		c;
	int			len;
	long long	nb;

	nb = (long long)nbr;
	len = ft_strlen(base);
	if (len < 2 || !ft_basecheck(base))
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	c = base[nb % len];
	if (nb / len != 0)
	{
		ft_putnbr_base(nb / len, base);
	}
	write(1, &c, 1);
}
