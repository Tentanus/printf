/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 16:15:30 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/02 17:55:42 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//INCLUDE

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

//DEFINITIONS

# ifndef DEF_CHAR
#  define DEF_CHAR = '%'
# endif

//FUNCTION
typedef int (*put_func) (va_list *)


#endif
