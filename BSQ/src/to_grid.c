/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:34:38 by mtarrih           #+#    #+#             */
/*   Updated: 2024/07/17 11:04:14 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	*allocate_row(char *buf, int offset)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * g_width);
	i = 0;
	while (i < g_width)
	{
		if (buf[i + offset] == g_empty)
			arr[i] = 1;
		else
			arr[i] = 0;
		i++;
	}
	return (arr);
}

int	**map_file_to_grid(char *filename)
{
	int		**grid;
	char	*buf;
	int		fd;
	char	c;
	int		i;

	fd = open(filename, O_RDONLY);
	c = 0;
	while (c != '\n')
		read(fd, &c, 1);
	grid = malloc(sizeof(int *) * g_height);
	buf = malloc(g_width + 1);
	i = 0;
	while (i < g_height)
	{
		read(fd, buf, g_width + 1);
		grid[i] = allocate_row(buf, 0);
		i++;
	}
	free(buf);
	return (grid);
}

int	**map_buf_to_grid(char *buf, int size)
{
	int		**grid;
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	grid = malloc(sizeof(int *) * g_height);
	j = 0;
	while (i < size)
	{
		grid[j++] = allocate_row(buf, i);
		i += g_width + 1;
	}
	free(buf);
	return (grid);
}
