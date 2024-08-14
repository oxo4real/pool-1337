/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:12:12 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/05 10:17:16 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	rendu;
	int	factor;

	if (nb < 0)
		return (0);
	rendu = 1;
	factor = 1;
	while (factor <= nb)
	{
		rendu *= factor;
		factor++;
	}
	return (rendu);
}
