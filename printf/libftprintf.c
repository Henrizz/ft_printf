/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:25:19 by Henriette         #+#    #+#             */
/*   Updated: 2023/12/06 22:12:44 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_conversion(const char format, va_list args)
{
	
}
// parse string until % is encountered, then check the next index for conversion sign
// then each conversion sign gets own situation
// return value is number of characters written
int ft_printf(const char *format, ...)
{
	int	length;
	int	i;
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
		{
			length = length + ft_printchar(format[i], args);
			i++;
		}
	}
	va_end(args);
	return(length);
}
