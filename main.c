/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 17:57:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/06/07 18:34:54 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int main(void){
	int		ret_cont;
	int		ret_test;
	char	str[] = "Testing:\n|%s|\n\0";
	char	test[] = "A string\0";

	printf("Control\t:\n");
	ret_cont = printf(str, test);
	printf("Case___\t:\n");
	ret_test = ft_printf(str, test);

	if (ret_cont != ret_test)
		printf("\n--==-- RETURN ERROR --==--\nControl_v_Case: %d v %d\n", ret_cont, ret_test);
	printf("--==-- FINISHED TESTING --==--\n");
	return (0);
}
