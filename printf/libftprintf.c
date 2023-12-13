/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:25:19 by Henriette         #+#    #+#             */
/*   Updated: 2023/12/13 18:20:45 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parse string until % is encountered, then check the next index for conv sign
// then each conversion sign gets own situation
// return value is number of characters written

#include "libftprintf.h"

static int	ft_conversion(const char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = ft_printchar(va_arg(args, int));
	else if (c == 's')
		length = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		length = ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		length = ft_printnbr(va_arg(args, int));
//	else if (c == 'u')
//	else if (c == 'x')
//	else if (c == 'X')
//	else if (c == '%')
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	int		i;
	va_list	args;

	length = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			length = length + ft_conversion(format[i + 1], args);
			i++;
		}
		else 
			length = length + ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}

int main(void)
{
	//int	num = 0;
	char	ptr[] = "Hallo string";
	ft_printf("%d\n", ptr);
	printf("%d\n", ptr);
	ft_printf("%s\n", ptr);
	return (0);
}
