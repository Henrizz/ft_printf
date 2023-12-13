/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printoutfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:10:46 by hzimmerm          #+#    #+#             */
/*   Updated: 2023/12/13 17:59:37 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	ft_printnbr(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		length++;
	}
	if (n >= 10)
		ft_printnbr(n / 10);
	ft_printchar(n % 10 + '0');
	length++;
	return (length);
}
