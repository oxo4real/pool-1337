/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:21:38 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/05 10:32:37 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	rendu;
	int	i;

	if (power < 0)
		return (0);
	rendu = 1;
	i = 0;
	while (i < power)
	{
		rendu *= nb;
		i++;
	}
	return (rendu);
}
