/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:45:54 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/07 12:53:58 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

int	ft_is_valid_input(char *input)
{
	int	i;

	if (ft_strlen(input) != 31)
		return (0);
	i = 0;
	while (input[i])
	{
		if (i % 2 == 0 && (input[i] < '0' || input[i] > '4'))
			return (0);
		if (i % 2 == 1 && input[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

//int main(void)
//{
//	printf("%i\n", ft_is_valid_input("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"));
//}
