/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/22 12:56:01 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	write(1, &c, 1);
	return (1);
}

int	put_str(va_list *list)
{
	char	*str;
	int		count;

	str = va_arg(*list, char *);
	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
		count++;
	write(1, str, (count));
	return (count);
}

int	put_poi(va_list *list)
{
	write(1, "0x", 2);
	return (2 + put_hex(list));
}

int	put_int(va_list *list)
{
	int		num;
	char	*str;

	num = va_arg(*list, int);
	str = ft_itoa((long) num);
	num = 0;
	while (str[num])
		num++;
	write(1, str, num);
	free(str);
	return (num);
}

int	put_hex(va_list *list)
{
	char			*set;
	unsigned long	n;


	set = "0123456789abcdef\0";
	n = va_arg(*list, unsigned long);
	while (n != 0)
	{
		n = n % 16;
	}
	return (0);
}

int	put_HEX(va_list *list)
{
	(void) list;

	return (write(1, "SHIT\0", 5));
}

int	put_prc(va_list *list)
{
	(void) list;
	write(1, "%", 1);
	return (1);
}
