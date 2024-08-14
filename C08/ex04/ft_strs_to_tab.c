/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:51:26 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/09 22:36:46 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock_str_arr;

	stock_str_arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_str_arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock_str_arr[i].size = ft_strlen(av[i]);
		stock_str_arr[i].str = av[i];
		stock_str_arr[i].copy = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if (!stock_str_arr[i].copy)
		{
			while (i > 0)
				free(stock_str_arr[--i].copy);
			free(stock_str_arr);
			return (NULL);
		}
		ft_strcpy(stock_str_arr[i].copy, av[i]);
		i++;
	}
	stock_str_arr[i].str = NULL;
	return (stock_str_arr);
}
