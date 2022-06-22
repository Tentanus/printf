/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 19:07:06 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/22 20:25:06 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static t_func	g_func_array[256] = {
['c'] = &put_char,
['s'] = &put_str,
['i'] = &put_int,
['d'] = &put_int,
['x'] = &put_hex,
['X'] = &put_HEX,
['%'] = &put_prc
};

int	ft_printf(const char *str, ...)
{
	int		strlen;
	int		strpos;
	va_list	arg;

	va_start(arg, str);
	strlen = 0;
	strpos = 0;
	while (str[strpos])
	{
		if (str[strpos] == FORMAT_CHAR)
		{
			strpos++;
			if (*g_func_array[(int) str[strpos]] == NULL)
				continue ;
			strlen += (*g_func_array[(int) str[strpos]])(&arg);
		}
		else
			strlen += write(1, &str[strpos], 1);
		strpos++;
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
