/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:45:05 by afoulqui          #+#    #+#             */
/*   Updated: 2021/01/11 16:51:42 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_strcpy(char *str)
{
	char	dst[500] = {0, };

	printf("\n   %sSTRCPY:%s '%s' => ", GREEN, RESET, str);
	printf("%s'%s'%s", YELLOW, strcpy(dst, str), RESET);

	printf("\n%sFT_STRCPY:%s '%s' => ", GREEN, RESET, str);
	printf("%s'%s'%s\n", YELLOW, ft_strcpy(dst, str), RESET);
}

void		ft_strcpy_test()
{
	test_strcpy(BASIC1);
	test_strcpy(BASIC2);
	test_strcpy(LONGSTR);
	test_strcpy(EMPTY);

	printf("%s", YELLOW);
	printf("\n(below in the test file (in comments), test to see if it's segfault if src = NULL :)\n");
	printf("%s", RESET);
	//printf("%s\n", ft_strcpy(NULL, BASIC1));
	printf("\n");
}