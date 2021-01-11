/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:57:45 by afoulqui          #+#    #+#             */
/*   Updated: 2021/01/11 16:55:04 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_strdup(const char *str)
{
	char *strs[2];

	strs[0] = NULL;
	strs[0] = strdup(str);
	printf("\n   %sSTRDUP:%s '%s' => ", GREEN, RESET, str);
	printf("%s'%s'%s", YELLOW, strs[0], RESET);

	strs[1] = NULL;
	strs[1] = ft_strdup(str);
	printf("\n%sFT_STRDUP:%s '%s' => ", GREEN, RESET, str);
	printf("%s'%s'%s\n", YELLOW, strs[1], RESET);

	free(strs[0]);
	free(strs[1]);
}

void		ft_strdup_test()
{
	test_strdup(BASIC1);
	test_strdup(BASIC2);
	test_strdup(LONGSTR);
	test_strdup(EMPTY);

	printf("%s", YELLOW);
	printf("\n(below in the test file (in comments), test to see if it's segfault if str = NULL :)\n");
	printf("%s", RESET);
	//printf("%s\n", ft_strdup(NULL));
	printf("\n");
}