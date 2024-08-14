/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:20:15 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/16 22:35:28 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_atoi(char *str);
int		get_op(char op);
void	add(int a, int b);
void	subtract(int a, int b);
void	multiply(int a, int b);
void	divide(int a, int b);
void	modulo(int a, int b);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

#endif
