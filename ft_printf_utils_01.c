/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/07/02 19:15:50 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(long n)
{
	int		i_len;
	char	*str;

	i_len = base_len(n, 10);
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

int	base_len(long n, int base)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= (long) base;
		len++;
	}
	return (len);
}

int	write_till(const char **str)
{
	int	count;

	count = 0;
	while ((*str)[count] && (*str)[count] != FORMAT_CHAR)
		count++;
	write(1, *str, count);
	*str += count;
	return (count);
}

void	ft_itoh_sub(char *set, char *str, unsigned int n)
{
	long	power;
	int		rem;
	int		i;
	short	flag;

	power = 4294967296;
	i = 0;
	flag = 0;
	while (power)
	{
		if ((n && power <= n) || flag)
		{
			flag = 1;
			rem = n / power;
			str[i++] = set[rem];
			while (n >= power)
				n -= power;
		}
		power /= 16;
	}
	return ;
}

char	*ft_itoh(unsigned int n)
{
	char	*set;
	char	*str;
	int		b_len;

	set = "0123456789abcdef\0";
	b_len = base_len((long) n, 16);
	str = malloc((b_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[b_len] = '\0';
	ft_itoh_sub(set, str, n);
	if (n == 0)
		str[0] = '0';
	return (str);
}

void	ft_strtoupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return ;
}
