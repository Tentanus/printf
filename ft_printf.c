/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 19:07:06 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/02 17:55:38 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const put_func func_array[256] = {
	['c'] = &put_char,
	['s'] = &put_str,
	['p'] = &put_poi,
	['d'] = &put_dec,
	['i'] = &put_int,
	['u'] = &put_uns_int,
	['x'] = &put_hex,
	['X'] = &put_HEX,
	['%'] = &put_prc,
}
//set = {cspdiuxX%}

int ft_printf(const char *str, ...)
{
	int strlen;
	int strpos;
	va_list arg;

	va_start(arg, str);
	strlen = 0;
	strpos = 0;
	while (str[strpos])
	{
		if (str[strpos] == DEF_CHAR)
		{
			strlen += (*put_func[(int) str[strpos + 1]])(&arg);
			strpos++;
		}
		else
			strlen += ft_putchar(str[strpos]);
		strpos++;
	}
	va_end(arg);
	return (strlen)
}

/*
 * Character			 c 
 * String				 s 
 * Pointer				 p 
 * Decimal				 d  
 * Interger				 i 
 * Unsigned Interger	 u 
 * Hexadecimal Lower	 x 
 * Hexadecimal Upper	 X 
 * Percentage Sign		 % 
 */
