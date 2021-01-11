/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:47:22 by afoulqui          #+#    #+#             */
/*   Updated: 2021/01/11 15:55:04 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int			main()
{
	printf("%s", PINK);
	printf("\n\t/*=======================*/");
	printf("\n\t/*       LIBASM 42       */");
	printf("\n\t/*         test.c        */");
	printf("\n\t/*=======================*/\n");
	printf("%s", RESET);

	printf("%s", CYAN);
	printf("\n--------------- TESTS FT_STRLEN.S ---------------\n");
	printf("%s", RESET);
	ft_strlen_test();

	printf("%s", CYAN);
	printf("\n--------------- TESTS FT_STRCMP.S ---------------\n");
	printf("%s", RESET);
	ft_strcmp_test();

	printf("%s", CYAN);
	printf("\n--------------- TESTS FT_STRCPY.S ---------------\n");
	printf("%s", RESET);
	ft_strcpy_test();

	printf("%s", CYAN);
	printf("\n--------------- TESTS FT_STRDUP.S ---------------\n");
	printf("%s", RESET);
	ft_strdup_test();
	
	printf("%s", CYAN);
	printf("\n--------------- TESTS FT_READ.S -----------------\n");
	printf("%s", RESET);
	ft_read_test();

	printf("%s", CYAN);
	printf("\n--------------- TESTS FT_WRITE.S ----------------\n");
	printf("%s", RESET);
	ft_write_test();

	return (0);
}


