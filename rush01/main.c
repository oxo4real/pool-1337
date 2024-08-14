/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:00:05 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/07 20:16:17 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_is_valid_input(char *input);
int		ft_find_solution_grid(int grid[4][4], int depth, 
			int row_col[2][4][2], int possible_inputs[2][24][4]);
void	traversal(int arr_ruse[24][4], int arr_target[24][4]);
void	ft_pars(int row_col[2][4][2], char *input);
void	ft_generate_combinations(int arr[24][4]);

int	main(int argc, char *argv[])
{
	int	row_col[2][4][2];
	int	possible_inputs[2][24][4];
	int	grid[4][4];
	int	depth;

	depth = 0;
	if (argc != 2 || !ft_is_valid_input(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_generate_combinations(possible_inputs[0]);
	traversal(possible_inputs[1], possible_inputs[0]);
	ft_pars(row_col, argv[1]);
	if (!ft_find_solution_grid(grid, depth, row_col, possible_inputs))
		write(1, "Error\n", 6);
}
