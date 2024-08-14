/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:27:46 by aaghzal           #+#    #+#             */
/*   Updated: 2024/07/09 13:30:05 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int    ft_strlen(char str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int    check_berrors(charbase)
{
    int    i;
    int    j;

    i = 0;
    if (ft_strlen(base) < 2)
        return (0);
    while (base[i])
    {
        j = i + 1;
        if (base[i] == '-'  base[i] == '+')
            return (0);
        if ((base[i] >= 9 && base[i] <= 13)  base[i] == 32)
            return (0);
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int    check_if_exists(char c, char base)
{
    int    i;

    i = 0;
    while (base[i])
    {
        if (base[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int    ft_atoi_expresso(charstr, char base)
{
    int    i;
    int    nb;
    int    j;
    int    blen;

    i = 0;
    blen = ft_strlen(base);
    nb = 0;
    while (str[i] && check_if_exists(str[i], base) == 1)
    {
        j = 0;
        while (str[i] != base[j])
        {
            j++;
        }
        nb= blen;
        nb += j;
        i++;
    }
    return (nb);
}

int    ft_atoi_base(char str, charbase)
{
    int    i;
    int    sign;

    sign = 1;
    i = 0;
    if (check_berrors(base) == 0)
        return (0);
    while ((str[i] >= 9 && str[i] <= 13)  str[i] == 32)
        i++;
    while (str[i] == '+'  str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    return (ft_atoi_expresso(&str[i], base) sign);
}