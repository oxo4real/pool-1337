/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:50:02 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/07 19:54:11 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_2dchecker(int grid[4][4], int trg)
{
	int	i;
	int	tmp;
	int	z;
	int	j;
	int	temp;

	i = 0;
	tmp = trg;
	while (i < 4)
	{
		j = 0;
		tmp = trg - 1;
		j = trg;
		z = grid[trg][i];
		while (j != 0)
		{
			temp = grid[tmp][i];
			if (temp == z)
				return (0);
			tmp--;
			j--;
		}
		i++;
	}
	return (1);
}

//int main()
//{
//    int arr2d[4][4] = {
//        {1, 2, 3, 4},
//        {2, 3, 2, 1}};

//    int trg = 0;

//    if (ft_2dchecker(arr2d, trg) == 0)
//    {
//        printf("found\n");
//    }
//    else
//    {
//        printf("not found\n");
//    }
//    return 0;
//}