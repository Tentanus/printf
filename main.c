/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@studend.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 17:57:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/23 18:14:02 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int main(void){

	int		ret_cont;
	int		ret_test;
	char	str[] = "test me baby |%qqq|   jajaja";
	char	test[] = "A string\0";

	printf("\n--==-- STARTING THE TEST --==--\n");
	ret_cont = printf(str, test);
	printf("\n");
	ret_test = ft_printf(str, test);

	if (ret_cont != ret_test)
		printf("\n--==-- RETURN ERROR --==--\nControl_v_Case: %d v %d\n", ret_cont, ret_test);

	printf("\n--==-- FINISHED TESTING --==--\n");
	return (0);
}
