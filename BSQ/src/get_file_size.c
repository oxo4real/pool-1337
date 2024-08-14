/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:35:02 by mtarrih           #+#    #+#             */
/*   Updated: 2024/07/17 17:37:44 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	get_file_size(char *filename)
{
	int	size;
	int	total_size;
	int	fd;

	total_size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		map_error();
	else
	{
		size = 1;
		while (size)
		{
			size = read(fd, g_buf, BUFSIZE);
			if (size == -1)
			{
				map_error();
				total_size = 0;
				break ;
			}
			total_size += size;
		}
		close(fd);
	}
	return (total_size);
}
