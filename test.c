/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 22:00:55 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/25 13:21:26 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

char *test_print(char *format, ...)
{
	int i;
	va_list arg;
	char *tmp;

	i = 1;
//	while (format[i])
//		if (format[i] == %)
//			val++;
	va_start(arg, format);
	i = 0;
	tmp = va_arg(arg, char *);
	while (tmp[i])
	{
		format[i] = tmp[i];
		i++;
	}
	va_end(arg);
	return (format);
}


int main()
{
	char *str;

	str = malloc(sizeof(char) * 5);
	printf("|%s|\n", test_print(str , "hier"));
	return (0);
}
