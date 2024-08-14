/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:34:55 by mtarrih           #+#    #+#             */
/*   Updated: 2024/07/17 21:08:47 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

char	*buffer_file(char *filename, int size)
{
	char	*buf;
	int		fd;

	fd = open(filename, O_RDONLY);
	buf = malloc(sizeof(char) * size);
	if (!buf)
		return (0);
	read(fd, buf, size);
	close(fd);
	return (buf);
}

void	for_each_file(char *filename)
{
	char	*buf;
	int		size;
	int		**grid;

	size = get_file_size(filename);
	if (size != 0)
	{
		buf = buffer_file(filename, size);
		if (buf && validate_map(buf, size))
		{
			free(buf);
			grid = map_file_to_grid(filename);
			biggest_square(grid, g_height, g_width);
			free_grid(grid);
		}
		else
			map_error();
	}
	else
		map_error();
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		noargs();
	else
	{
		i = 1;
		while (i < ac)
		{
			for_each_file(av[i]);
			i++;
		}
	}
}
