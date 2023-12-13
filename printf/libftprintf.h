/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:17:58 by Henriette         #+#    #+#             */
/*   Updated: 2023/12/13 18:03:01 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printnbr(int n);
int	ft_putptr(unsigned long long ptr);
int	ft_conv_print_ptr(uintptr_t n);

#endif
