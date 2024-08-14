/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:21:53 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/06 16:16:12 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_cmp(char *str, char *to_find, int i)
{
	int		k;

	k = 0;
	while (to_find[k] != 0)
	{
		if (to_find[k] != str[i])
			return (0);
		i++;
		k++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	if (*to_find == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_cmp(str, to_find, i))
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}
