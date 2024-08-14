/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:34:41 by mtarrih           #+#    #+#             */
/*   Updated: 2024/07/16 21:34:41 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_atoi(char *buf, int size, int *inc)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size && (buf[i] >= '0' && buf[i] <= '9'))
	{
		res = res * 10 + buf[i] - '0';
		i++;
	}
	*inc = i;
	return (res);
}

int	is_first_line_valid(char *buf, int size, int i)
{
	if (i + 3 + 1 >= size || buf[i + 3] != '\n')
		return (0);
	g_empty = buf[i + 0];
	g_obstacle = buf[i + 1];
	g_full = buf[i + 2];
	return (
		(g_empty != g_obstacle) && (g_empty != g_full)
		&& (g_obstacle != g_full)
	);
}

int	on_newline(int *width, int *prev_width, int *lines_count)
{
	if (*prev_width != -1 && *width != *prev_width)
		return (0);
	*prev_width = *width;
	*width = 0;
	(*lines_count)++;
	return (1);
}

int	validate(char *buf, int size, int i, int target_lines_count)
{
	int	width;
	int	prev_width;
	int	lines_count;

	lines_count = 0;
	prev_width = -1;
	width = 0;
	while (i < size)
	{
		if (buf[i] == '\n')
		{
			if (!on_newline(&width, &prev_width, &lines_count))
				return (0);
		}
		else
		{
			if (buf[i] != g_empty && buf[i] != g_obstacle)
				return (0);
			width++;
		}
		i++;
	}
	g_width = prev_width;
	return (lines_count == target_lines_count);
}

/*
	1. Checks line count, if it's 0 we return
	2. Checks if the first line has enough space to house map symbols
		and makes sure there's a new line
	3. Checks if symbols are unique
*/
int	validate_map(char *buf, int size)
{
	int	target_lines_count;
	int	i;

	target_lines_count = ft_atoi(buf, size, &i);
	if (target_lines_count == 0)
		return (0);
	if (!is_first_line_valid(buf, size, i))
		return (0);
	if (!validate(buf, size, i + 4, target_lines_count))
		return (0);
	g_height = target_lines_count;
	return (1);
}
