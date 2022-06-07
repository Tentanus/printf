/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/07 18:34:44 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(va_list *list){
	char	c;

	c = va_arg(*list, int);
	write(1, &c, 1);
	return(1);
}

int	put_str(va_list *list){
	char	*str;
	int		count;

	str = va_arg(*list, char *);
	count = 0;
	if (str = NULL){
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count]){
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	put_poi(va_list *list){
	int len;


	write(1, "0x", 2);
	len = 0;

	return (2 + );
}

int	put_dec(va_list *list){
	
}

int	put_int(va_list *list){
	
}

int	put_uns_int(va_list *list){
	
}

int	put_hex(va_list *list){
	
}

int	put_HEX(va_list *list){
	
}

int	put_prc(va_list *list){
	(void) list;
	write(1, '%', 1);
	return (1);
}
