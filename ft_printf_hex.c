/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/07/02 18:23:18 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_poi(va_list *list)
{
	write(1, "0x", 2);
	return (2 + put_hex(list));
}

int	put_hex(va_list *list)
{
	char			*str;
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	str = ft_itoh(n);
	if (!str)
		return (0);
	n = (unsigned int) base_len(n, 16);
	write(1, str, n);
	free(str);
	return ((int) n);
}

int	put_hex_up(va_list *list)
{
	char			*str;
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	str = ft_itoh(n);
	if (!str)
		return (0);
	n = (unsigned int) base_len(n, 16);
	ft_strtoupper(str);
	write(1, str, n);
	free(str);
	return ((int) n);
}
