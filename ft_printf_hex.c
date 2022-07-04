/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/07/04 21:01:15 by mweverli      ########   odam.nl         */
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
	unsigned long	n;
	int				len;

	n = (unsigned long) va_arg(*list, (void *));
	str = ft_itoh(n);
	if (!str)
		return (0);
	len = base_len(n, 16);
	write(1, str, len);
	free(str);
	return (len);
}

int	put_hex_up(va_list *list)
{
	char			*str;
	unsigned long	n;

	n = va_arg(*list, unsigned long);
	str = ft_itoh(n);
	if (!str)
		return (0);
	n = (unsigned long) base_len(n, 16);
	ft_strtoupper(str);
	write(1, str, n);
	free(str);
	return ((int) n);
}
