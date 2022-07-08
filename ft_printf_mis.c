/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:26:14 by mweverli      #+#    #+#                 */
/*   Updated: 2022/07/08 22:23:18 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_prc(va_list list)
{
	(void) list;
	write(1, "%", 1);
	return (1);
}
