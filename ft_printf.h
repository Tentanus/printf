/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 16:15:30 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/08 15:32:32 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//INCLUDE

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

//DEFINITIONS

# ifndef FORMAT_CHAR
#  define FORMAT_CHAR '%'
# endif

//FUNCTION
typedef int		(*put_func) (va_list *);
int				ft_printf(const char *str, ...);
//printf_utils_01
int				put_char(va_list *list);
int				put_str(va_list *list);
int				put_poi(va_list *list);
int				put_hex(va_list *list);
int				put_HEX(va_list *list);
int				put_int(va_list *list);
int				put_prc(va_list *list);
//printf_utils_02
char			*ft_itoa(long n);
int				int_len(long num);


static const	put_func func_array[256] = {
	['c'] = &put_char,
	['s'] = &put_str,
	['i'] = &put_int,
	['d'] = &put_int,
	['x'] = &put_hex,
	['X'] = &put_HEX,
	['%'] = &put_prc
};


#endif
