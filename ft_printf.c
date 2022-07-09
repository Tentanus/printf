/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 19:07:06 by mweverli      #+#    #+#                 */
/*   Updated: 2022/07/09 15:37:11 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_func	g_func_array[256] = {
['c'] = &put_char,
['s'] = &put_str,
['i'] = &put_int,
['u'] = &put_uint,
['d'] = &put_int,
['x'] = &put_hex,
['X'] = &put_hex_up,
['p'] = &put_poi,
['%'] = &put_prc
};

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
			if (*g_func_array[(int) *str] != NULL)
				strlen += (*g_func_array[(int) *str++])(arg);
			else
			{
				str++;
				continue ;
			}
		}
	}
	va_end(arg);
	return (strlen);
}
