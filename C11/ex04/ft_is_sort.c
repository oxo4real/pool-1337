/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:24:16 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/15 12:24:16 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	asc;
	int	dsc;

	i = 0;
	j = 1;
	asc = 1;
	dsc = 1;
	while (j < length)
	{
		if (f(tab[i], tab[j]) > 0)
			asc = 0;
		if (f(tab[i], tab[j]) < 0)
			dsc = 0;
		i++;
		j++;
	}
	return (asc || dsc);
}
