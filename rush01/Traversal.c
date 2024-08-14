/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:59:11 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/07 20:12:47 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	calculate_j(int arr_target[24][4], int i_arr_target, int *j)
{
	int	tmp;
	int	i;
	int	x;

	tmp = 0;
	i = 0;
	while (i < 4)
	{
		x = arr_target[i_arr_target][i];
		if (tmp < x)
		{
			tmp = x;
			(*j)++;
		}
		i++;
	}
}

void	calculate_z(int arr_target[24][4], int i_arr_target, int *z)
{
	int	tmp;
	int	i;
	int	x;

	tmp = 0;
	i = 3;
	while (i >= 0)
	{
		x = arr_target[i_arr_target][i];
		if (tmp < x)
		{
			tmp = x;
			(*z)++;
		}
		i--;
	}
}

void	traversal(int arr_ruse[24][4], int arr_target[24][4])
{
	int	i_arr_target;
	int	j;
	int	z;

	i_arr_target = 0;
	while (i_arr_target < 24)
	{
		j = 0;
		z = 0;
		calculate_j(arr_target, i_arr_target, &j);
		calculate_z(arr_target, i_arr_target, &z);
		arr_ruse[i_arr_target][0] = j;
		arr_ruse[i_arr_target][1] = z;
		i_arr_target++;
	}
}
