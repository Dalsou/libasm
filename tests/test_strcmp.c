/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:28:26 by afoulqui          #+#    #+#             */
/*   Updated: 2021/01/11 16:51:40 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_strcmp(char *s1, char *s2)
{
	printf("\n   %sSTRCMP:%s '%s' & '%s' => ", GREEN, RESET, s1, s2);
	printf("%s%d%s", YELLOW, strcmp(s1, s2), RESET);

	printf("\n%sFT_STRCMP:%s '%s' & '%s' => ", GREEN, RESET, s1, s2);
	printf("%s%d%s\n", YELLOW, ft_strcmp(s1, s2), RESET);
}

void		ft_strcmp_test()
{
	test_strcmp(BASIC1, BASIC1);
	test_strcmp(BASIC1, BASIC2);
	test_strcmp(BASIC2, BASIC1);
	test_strcmp(BASIC1, EMPTY);
	test_strcmp(EMPTY, BASIC1);

	printf("%s", YELLOW);
	printf("\n(below in the test file (in comments), test to see if it's segfault if one string is NULL)\n");
	printf("%s", RESET);
	//printf("%d\n", ft_strcmp(BASIC1, NULL));
	//printf("%d\n", ft_strcmp(NULL, BASIC1));
	printf("\n");
}