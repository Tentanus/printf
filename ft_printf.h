/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 16:15:30 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/23 18:14:04 by mweverli      ########   odam.nl         */
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
typedef int		(*t_func) (va_list *);
int				ft_printf(const char *str, ...);
int				write_till(const char **str);
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

#endif
