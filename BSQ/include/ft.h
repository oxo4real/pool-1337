/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:57:21 by mtarrih           #+#    #+#             */
/*   Updated: 2024/07/16 21:58:56 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFSIZE 1024

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

extern char	g_buf[BUFSIZE];

extern char	g_empty;
extern char	g_obstacle;
extern char	g_full;
extern int	g_width;
extern int	g_height;

int		get_file_size(char *filename);
int		validate_map(char *buf, int size);
void	biggest_square(int **int_grid, int height, int width);
int		**map_file_to_grid(char *filename);
int		**map_buf_to_grid(char *buf, int size);
void	free_grid(int **grid);
void	noargs(void);

void	ft_writestr(int fd, char *str);
void	map_error(void);

#endif
