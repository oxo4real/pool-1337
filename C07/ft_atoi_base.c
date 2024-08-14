/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:25:00 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/09 13:52:51 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_basecheck(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
		return (0);
	while (base[i + 1] != 0)
	{
		j = i + 1;
		if (base[j] == '+' || base[j] == '-' || base[j] <= ' ')
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

int	ft_char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

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

int	ft_pos_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	neg;
	int	num;
	int	i;
	int	len;

	len = ft_strlen(base);
	if (!ft_basecheck(base))
		return (0);
	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_char_in_base(str[i], base))
	{
		num = num * len + ft_pos_in_base(str[i], base);
		i++;
	}
	return (num * neg);
}
int main(void)
{
	printf("%i", ft_atoi_base("0100", "01"));
}
