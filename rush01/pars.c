/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:07:40 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/08 13:21:54 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_pars(int row_col[2][4][2], char *input)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = i + 8;
	k = -1;
	while (++k < 4)
	{
		row_col[1][k][0] = input[i] - '0';
		row_col[1][k][1] = input[j] - '0';
		i += 2;
		j += 2;
	}
	k = -1;
	i = 16;
	j = i + 8;
	while (++k < 4)
	{
		row_col[0][k][0] = input[i] - '0';
		row_col[0][k][1] = input[j] - '0';
		i += 2;
		j += 2;
	}
}
//4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2
int main(void)
{
	int row_col[2][4][2];

	ft_pars(row_col, "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
	printf("col:\n");
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("%i ", row_col[1][i][j]);
		}
		printf("\n");
	}
	printf("row:\n");
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("%i ", row_col[0][i][j]);
		}
		printf("\n");
	}
}
