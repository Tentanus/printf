/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 19:07:06 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/23 18:03:33 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static const t_func	g_func_array[256] = {
['c'] = &put_char,
['s'] = &put_str,
['i'] = &put_int,
['d'] = &put_int,
['x'] = &put_hex,
['X'] = &put_HEX,
['%'] = &put_prc
};

int	write_till(const char **str)
{
	int	count;

	count = 0;
	while ((*str)[count] && (*str)[count] != FORMAT_CHAR)
		count++;
	write(1, *str, count);
	*str += count - 1;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		strlen;
	va_list	arg;

	va_start(arg, str);
	strlen = 0;
	while (*str)
	{
		if (*str != FORMAT_CHAR)
			strlen += write_till(&str);
		else
		{
			str++;
			if (*g_func_array[(int) *str++] == NULL)
				continue ;
			strlen += (*g_func_array[(int) *str])(&arg);
		}
		str++;
	}
	va_end(arg);
	return (strlen);
}

/*
 * Character			 c 
 * String				 s 
 * Pointer				 p 
 * Decimal				 d |
 * Interger				 i |
 * Unsigned Interger	 u  
 * Hexadecimal Lower	 x |
 * Hexadecimal Upper	 X |
 * Percentage Sign		 % 
 */
