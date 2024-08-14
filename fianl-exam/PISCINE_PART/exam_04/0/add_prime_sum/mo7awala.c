/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo7awala.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:35:31 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/18 13:03:39 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_prime(int nb)
{
	int i;

	if(nb < 2)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	putnbr(int nb)
{
	unsigned int	abs;
	char			c;

	abs = nb;

	if (nb < 0)
	{
		write(1, "-", 1);
		abs = ~0u - abs + 1;
	}
	if (abs / 10 != 0)
		putnbr(abs / 10);
	c = abs % 10 + '0';
	write(1, &c, 1);
}

int atoi(char *str)
{
	int	num;
	int	i;
	int signe;

	i = 0;
	num = 0;
	signe = 1;
	while (str[i] <= ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * signe);
}

int main(int ac, char *av[])
{
	int rendu;
	int	num;
	int i;

	rendu = 0;
	i = 0;
	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num >= 0)
		{
			while (i <= num)
			{
				if (is_prime(i))
					rendu += i;
				i++;
			}
		}
	}
	putnbr(rendu);
	write(1, "\n", 1);
}

//#include <stdio.h>

//is_prime test:
//int main(void)
//{
//	printf("%i\n", is_prime(2));
//	printf("%i\n", is_prime(5));
//	printf("%i\n", is_prime(13));
//	printf("%i\n", is_prime(8));
//	printf("%i\n", is_prime(10));
//	printf("%i\n", is_prime(1));
//	printf("%i\n", is_prime(0));
//	printf("%i\n", is_prime(-20));
//}

//putnbr test:
//int main(void)
//{
//	putnbr(2);
//	printf("\n");
//	putnbr(5);
//	printf("\n");
//	putnbr(13);
//	printf("\n");
//	putnbr(8);
//	printf("\n");
//	putnbr(10);
//	printf("\n");
//	putnbr(1);
//	printf("\n");
//	putnbr(0);
//	printf("\n");
//	putnbr(-20);
//	printf("\n");
//	putnbr(2147483647);
//	printf("\n");
//	putnbr(-2147483648);
//	printf("\n");
//}

//atoi test:
//int main(void)
//{
//	printf("%i\n", atoi("2"));
//	printf("%i\n", atoi("a5"));
//	printf("%i\n", atoi("13"));
//	printf("%i\n", atoi("--8"));
//	printf("%i\n", atoi("  ---+10"));
//	printf("%i\n", atoi("1"));
//	printf("%i\n", atoi("0"));
//	printf("%i\n", atoi("-20"));
//}