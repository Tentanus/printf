/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 20:53:26 by mweverli      #+#    #+#                 */
/*   Updated: 2021/12/19 15:32:09 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main (void)
{
	int i = 308109;

	printf("Column    123456789 123456789 123456789\n");
	printf("Output:  |%-5i|", i);
	return (0);
}
