/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:01:21 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/01 16:20:48 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] > 'z' || str[i] < 'A' || (str[i] < 'a' && str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}
