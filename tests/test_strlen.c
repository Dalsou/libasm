/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:10:11 by afoulqui          #+#    #+#             */
/*   Updated: 2021/01/11 16:54:19 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_strlen(char *str)
{
	printf("\n   %sSTRLEN:%s '%s' => ", GREEN, RESET, str);
	printf("%s%ld%s", YELLOW, strlen(str), RESET);

	printf("\n%sFT_STRLEN:%s '%s' => ", GREEN, RESET, str);
	printf("%s%ld%s\n", YELLOW, ft_strlen(str), RESET);
}

void		ft_strlen_test()
{
	test_strlen(BASIC1);
	test_strlen(EMPTY);
	test_strlen(LONGSTR);

	printf("%s", YELLOW);
	printf("\n(below in the test file (in comments), test to see if it's segfault if NULL:)\n");
	printf("%s", RESET);
	//printf("%ld\n", ft_strlen(NULL));

	printf("\n");
}