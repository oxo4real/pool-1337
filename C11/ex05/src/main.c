/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:53:19 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/16 19:53:19 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		i;
	void	(*funcs[5])(int, int);

	funcs[0] = add;
	funcs[1] = subtract;
	funcs[2] = multiply;
	funcs[3] = divide;
	funcs[4] = modulo;
	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	i = get_op(argv[2][0]);
	if (i >= 0)
		funcs[i](a, b);
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
