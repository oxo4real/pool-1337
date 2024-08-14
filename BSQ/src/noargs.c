/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noargs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:34:47 by mtarrih           #+#    #+#             */
/*   Updated: 2024/07/17 11:06:27 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

typedef struct s_node {
	struct s_node	*next;
	char			*data;
	int				size;
}	t_node;

char	*bufdup(char *buf, int size)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = buf[i];
		i++;
	}
	return (dup);
}

void	foreach_io(char *buf, int size, t_node **prev, t_node **head)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->size = size;
	node->data = bufdup(buf, size);
	node->next = 0;
	if (*prev)
		(*prev)->next = node;
	if (!(*head))
		*head = node;
	*prev = node;
}

void	solve(char *buf, int size)
{
	int		**grid;

	if (validate_map(buf, size))
	{
		grid = map_buf_to_grid(buf, size);
		biggest_square(grid, g_height, g_width);
		free_grid(grid);
	}
	else
		map_error();
}

void	merge_list(t_node *head, int size)
{
	int		i;
	int		j;
	char	*buf;
	t_node	*next;

	buf = malloc(sizeof(char) * size);
	i = 0;
	while (head)
	{
		j = 0;
		while (j < head->size)
		{
			buf[i] = head->data[j];
			i++;
			j++;
		}
		next = head->next;
		free(head->data);
		free(head);
		head = next;
	}
	solve(buf, size);
}

void	noargs(void)
{
	int		size;
	int		total_size;
	t_node	*prev;
	t_node	*head;

	total_size = 0;
	prev = 0;
	head = 0;
	while (1)
	{
		size = read(0, g_buf, BUFSIZE);
		if (size == -1)
		{
			map_error();
			return ;
		}
		if (size == 0)
			break ;
		foreach_io(g_buf, size, &prev, &head);
		total_size += size;
	}
	merge_list(head, total_size);
}
