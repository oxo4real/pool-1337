/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:40:30 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/03 13:18:13 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	j;
	int				dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	if (size <= (unsigned int)dest_len)
		return (size + ft_strlen(src));
	if (size - (dest_len + 1))
	{
		while (dest[i] != 0)
		{
			i++;
		}
		j = 0;
		while (src[j] != 0 && j < size - (dest_len + 1))
		{
			dest[i] = src[j];
			j++;
			i++;
		}
		dest[i] = 0;
	}
	return (dest_len + ft_strlen(src));
}
