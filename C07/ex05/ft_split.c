/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:46:25 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/13 14:13:38 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcpy_v2(char *dest, char *src, char *charset)
{
	int		i;

	i = 0;
	while (!is_in_charset(src[i], charset) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	c_count(int pos, char *str, char *charset)
{
	int	len;

	len = 0;
	while (!is_in_charset(str[pos], charset) && str[pos])
	{
		len += 1;
		pos++;
	}
	return (len);
}

void	fill_arr(char **arr, char *str, char *charset)
{
	int	is_word;
	int	count;
	int	i;

	i = 0;
	is_word = 0;
	count = 0;
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			arr[count] = malloc(sizeof(char) * (c_count(i, str, charset) + 1));
			ft_strcpy_v2(arr[count], &str[i], charset);
			count += 1;
		}
		i++;
	}
	arr[count] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		is_word;
	int		count;
	int		i;

	i = 0;
	is_word = 0;
	count = 0;
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			count += 1;
		}
		i++;
	}
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	fill_arr(arr, str, charset);
	return (arr);
}
