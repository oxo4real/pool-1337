/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:08 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/11 12:06:38 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_in_str(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_base(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_in_str(str, str[i], i))
			return (0);
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	print_base(long nbrl, char *base, int base_len)
{
	int	arr[40];
	int	i;

	i = 0;
	while (nbrl > 0)
	{
		arr[i] = nbrl % base_len;
		nbrl /= base_len;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &base[arr[i]], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbrl;
	int		base_len;

	if (!ft_check_base(base))
		return ;
	base_len = ft_check_base(base);
	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	nbrl = nbr;
	if (nbrl < 0)
	{
		write(1, "-", 1);
		nbrl *= -1;
	}
	print_base(nbrl, base, base_len);
}
