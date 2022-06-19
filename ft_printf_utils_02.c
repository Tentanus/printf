/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/08 15:32:26 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_itoa(long n)
{
	int		i_len;
	char	*str;

	i_len = int_len(n);
	str = malloc((i_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i_len] = '\0';
	i_len--;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	else if (n == 0)
		str[0] = '0';
	while (n > 0 && i_len >= 0)
	{
		str[i_len] = '0' + (n % 10);
		n /= 10;
		i_len--;
	}
	return (str);
}

int int_len(long num)
{
	int len;

	len = 0;
	if (num <= 0)
	{
		num *= -1;
		len++;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

