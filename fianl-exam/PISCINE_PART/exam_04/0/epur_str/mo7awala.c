/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo7awala.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:06:50 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/18 21:20:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
	int i;
	int is_word;
	int wordsprinted;

	i = 0;
	is_word = 1;
	wordsprinted = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (!(av[1][i] == ' ' || (av[1][i] <= 13 && av[1][i] >= 9)))
			{
				if (!is_word && wordsprinted)
					write(1, " ", 1);
				write(1, &av[1][i], 1);
				is_word = 1;
				wordsprinted += 1;
			}
			else {
				is_word = 0;
			}
			i++;
		}
	}
}