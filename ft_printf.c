/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 19:07:06 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/08 15:32:21 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (str[strpos] == FORMAT_CHAR)
		{
			if (*func_array[(int) str[strpos + 1]] == NULL)
				return (strlen);
			strlen += (*func_array[(int) str[strpos + 1]])(&arg);
			strpos++;
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
