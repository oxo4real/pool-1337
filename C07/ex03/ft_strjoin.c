/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:44:11 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/10 18:58:12 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != 0)
	{
		i++;
	}
	j = 0;
	while (src[j] != 0)
	{
		dest[i] = src[j];
		j++;
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

int	strsize_calc(char **strs, char *sep, int size)
{
	int	i;
	int	strsize;

	i = 0;
	strsize = 0;
	while (i < size)
	{
		strsize += ft_strlen(strs[i]);
		if (i < size - 1)
			strsize += ft_strlen(sep);
		i++;
	}
	strsize += 1;
	return (strsize);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*rendu;
	int		i;
	int		strsize;

	i = 0;
	strsize = strsize_calc(strs, sep, size);
	rendu = malloc(sizeof(char) * strsize);
	if (!rendu)
		return (NULL);
	rendu[0] = 0;
	if (!size)
		return (rendu);
	while (i < size)
	{
		ft_strcat(rendu, strs[i]);
		if (i < size - 1)
			ft_strcat(rendu, sep);
		i++;
	}
	return (rendu);
}
