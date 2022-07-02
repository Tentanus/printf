/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@studend.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 17:57:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/07/02 14:40:09 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int main(void){

//*
	int		ret_cont;
	int		ret_test;
	char	str[] = "test me baby |%u|\n\0";
//	char	test[] = "A string\0";
	long		test = 4294967298;

	printf("\n--==-- STARTING THE TEST --==--\n\n");
	ret_cont = printf(str, test);
	ret_test = ft_printf(str, test);

	if (ret_cont != ret_test)
		printf("\n--==-- RETURN ERROR --==--\nControl_v_Case: %d v %d\n", ret_cont, ret_test);
	printf("\n--==-- FINISHED TESTING --==--\n");

//*/

/*
	long	n = 654543774;
	char	*b10 = ft_itoa(n);
//	char	*b16;

	printf("16:\t%d\t\n10:\t%d\t%s\n", base_len(n, 16), base_len(n, 10), b10);
	free(b10);

*/
	return (0);
}
