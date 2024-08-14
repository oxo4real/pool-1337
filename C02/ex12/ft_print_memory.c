/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:46:28 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/02 18:55:03 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	ft_print_0(unsigned long long hex)
{
	int		length;
	int		j;

	length = 0;
	while (hex > 0)
	{
		length++;
		hex /= 16;
	}
	j = 0;
	while (j < 16 - length)
	{
		write(1, "0", 1);
		j++;
	}
}

void	ft_print_int_in_hex(unsigned long long i)
{
	if (i == 0)
	{
		return ;
	}
	ft_print_int_in_hex(i / 16);
	write(1, &"0123456789abcdef"[i % 16], 1);
}

void	ft_print_16_hex(char *ptr, int size)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i < size)
		{
			if ((unsigned char)ptr[i] < 16)
				write(1, "0", 1);
			if ((unsigned char)ptr[i] == 0)
				write(1, "0", 1);
			ft_print_int_in_hex((unsigned char)ptr[i]);
		}
		else 
			write(1, "  ", 2);
		i++;
	}
}

void	ft_print(char *ptr, int size)
{
	int		i;

	i = 0;
	while (i < size && i < 16)
	{
		if ((unsigned char)ptr[i] >= 32 && (unsigned char)ptr[i] <= 126)
			write(1, &ptr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char				*ptr;
	int					size2;
	unsigned long long	address;

	size2 = size;
	ptr = addr;
	address = (unsigned long long)addr;
	while (size2 > 0)
	{
		ft_print_0(address);
		ft_print_int_in_hex(address);
		write(1, ": ", 1);
		ft_print_16_hex(ptr, size2);
		write(1, " ", 1);
		ft_print(ptr, size2);
		write(1, "\n", 1);
		size2 -= 16;
		ptr += 16;
		address += 16;
	}
	return (addr);
}
