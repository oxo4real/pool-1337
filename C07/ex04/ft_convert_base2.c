/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:21:21 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/13 17:49:02 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_basecheck(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_rendu_len(int nbr, int base_len)
{
	int				i;
	long long int	nbrl;

	nbrl = nbr;
	i = 0;
	if (nbrl < 0)
	{
		nbrl *= -1;
		i += 1;
	}
	if (nbrl == 0)
		i++;
	while (nbrl > 0)
	{
		nbrl /= base_len;
		i++;
	}
	i++; 
	return (i);
}

int	calc_num_width_base(unsigned int n, unsigned int radix)
{
	int	width;

	width = 1;
	while (n / radix != 0)
	{
		width += 1;
		n = n / radix;
	}
	return (width);
}

void	convert(int nbr, int width, int radix)
{
	int		i;
	char	*rendu;

	rendu = malloc(sizeof(char) * (width + 1));
	i = 0;
	while (nbr / radix != 0)
	{
		nbr = nbr / radix;
	}
}

char	*ft_itoa_base(int nbr, char *base)
{
	unsigned int	abs;
	unsigned int	width;
	char			*rendu;
	int				sign;

	abs = nbr;
	sign = 1;
	if (nbr < 0)
	{
		abs = ~0u - abs + 1;
		sign = -1;
	}
	width = calc_num_width_base(abs, ft_strlen(base));
	if (sign == -1)
		width += 1;
	rendu = malloc(sizeof(char) * (width + 1));
	rendu[width] = '\0';
	while (width != 0)
	{
		rendu[--width] = base[abs % ft_strlen(base)];
		abs = abs / ft_strlen(base);
	}
	if (sign == -1)
		rendu[0] = '-';
	return (rendu);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	mid_num;

	if (!ft_basecheck(base_from) || !ft_basecheck(base_to))
		return (NULL);
	mid_num = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(mid_num, base_to));
}
