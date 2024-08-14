/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   narayana_pandita.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:18:41 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/08 10:05:38 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_reverse(int arr[], int start, int end)
{
	while (start < end)
	{
		ft_swap(&arr[start], &arr[end]);
		start++;
		end--;
	}
}

void	ft_innit(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i + 1;
		i++;
	}
}

void	ft_generate_combinations(int arr[24][4])
{
	int	i;
	int	j;
	int	k;

	k = 1;
	ft_innit(arr[0], 4);
	while (k < 24)
	{
		i = -1;
		while (++i < 4)
			arr[k][i] = arr[k - 1][i];
		i = 4 - 1;
		while (i > 0 && arr[k][i] < arr[k][i - 1])
			i--;
		if (i < 0)
			break ;
		j = 4 - 1;
		while (arr[k][j] < arr[k][i - 1])
			j--;
		ft_swap(&arr[k][i - 1], &arr[k][j]);
		ft_reverse(arr[k], i, 4 - 1);
		k++;
	}
}

int main() {
	int	arr[24][4];

	ft_generate_combinations(arr);
    for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%i ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
