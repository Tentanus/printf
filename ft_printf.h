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
int				put_char(va_list *list);
int				put_str(va_list *list);
int				put_poi(va_list *list);
int				put_prc(va_list *list);

static const	put_func func_array[256] = {
	['c'] = &put_char,
	['s'] = &put_str,
	['p'] = &put_poi,
	['%'] = &put_prc
};


#endif
