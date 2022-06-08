/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/08 21:06:54 by vincent       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "example_strlen.c"

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
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen(str); // syscals are considered "slow" see strlen_benchmark.c for an example
	write(1, str, count);
	return (count);
}

int	put_poi(va_list *list)
{
	const char	set[] = "0123456789abcdef";
	int		len;

	write(1, "0x", 2);
	len = 0;
	(void)list;
	(void)set;
	return (2 + len);
}

//
//int	put_dec(va_list *list){
//	
//}
//
//int	put_int(va_list *list){
//	
//}
//
//int	put_uns_int(va_list *list){
//	
//}
//
//int	put_hex(va_list *list){
//	
//}
//
//int	put_HEX(va_list *list){
//	
//}
//
int	put_prc(va_list *list)
{
	(void) list;
	write(1, "%", 1);
	return (1);
}
