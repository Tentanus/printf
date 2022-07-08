/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/07/08 22:23:44 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(va_list list)
{
	char	c;

	c = va_arg(list, int);
	write(1, &c, 1);
	return (1);
}

int	put_str(va_list list)
{
	char	*str;
	int		count;

	str = va_arg(list, char *);
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
