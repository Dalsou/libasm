/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:43:23 by afoulqui          #+#    #+#             */
/*   Updated: 2021/01/11 17:01:04 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		original_read(int fd, int len)
{
	char	*buff;
    ssize_t	ret;
	
	buff = NULL;
	ret = 0;
	if (!(buff = (char *)malloc(len + 1)))
		return ;
	bzero(buff, len + 1);
	ret = read(fd, buff, len);
	printf("   %sREAD BUF:%s ", GREEN, RESET);
	printf("%s%s%s\n", YELLOW, buff, RESET);
	printf("   %sREAD RETURN:%s ", GREEN, RESET);
	printf("%s%zd%s\n", YELLOW, ret, RESET);
	free(buff);
}

void		my_read(int fd, int len)
{
    char	*buff;
    ssize_t	ret;

	buff = NULL;
	ret = 0;
	if (!(buff = (char *)malloc(len + 1)))
		return ;
	bzero(buff, len + 1);
	ret = ft_read(fd, buff, len);
	printf("%sFT_READ BUF:%s ", GREEN, RESET);
	printf("%s%s%s\n", YELLOW, buff, RESET);
	printf("%sFT_READ RETURN:%s ", GREEN, RESET);
	printf("%s%zd%s\n", YELLOW, ret, RESET);
	free(buff);
}

void			ft_read_test()
{
	int		fd;

	printf("\n\n%s*** READING TEXT.TXT ***%s\n\n", PINK, RESET);

	errno = 0;
	fd = 0;
	if (!(fd = open("tests/txt_files/text.txt", O_RDONLY)))
	{
		printf("\n%sError in fd%s\n", RED, RESET);
		return ;
	}
	original_read(fd, 100);
	printf("   %sREAD ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s", YELLOW, errno, RESET);
	close(fd);
	printf("\n");

	errno = 0;
	fd = 0;
	if (!(fd = open("tests/txt_files/text.txt", O_RDONLY)))
	{
		printf("\n%sError in fd%s\n", RED, RESET);
		return ;
	}
	my_read(fd, 100);
	printf("%sFT_READ ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n", YELLOW, errno, RESET);
	close(fd);

	printf("\n\n%s*** READING FD = -1 ***%s\n\n", PINK, RESET);

	errno = 0;
	fd = -1;
	original_read(fd, 100);
	printf("   %sREAD ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n", YELLOW, errno, RESET);
	printf("   %sREAD ERRNO MSG:%s ", GREEN, RESET);
	printf("%s%s%s\n", YELLOW, strerror(errno), RESET);
	printf("\n");

	errno = 0;
	fd = -1;
	my_read(fd, 100);
	printf("%sFT_READ ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n", YELLOW, errno, RESET);
	printf("%sFT_READ ERRNO MSG:%s ", GREEN, RESET);
	printf("%s%s%s\n", YELLOW, strerror(errno), RESET);

	printf("\n\n%s*** READING FD = 75 ***%s\n\n", PINK, RESET);

	errno = 0;
	fd = 75;
	original_read(fd, 100);
	printf("   %sREAD ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n", YELLOW, errno, RESET);
	printf("   %sREAD ERRNO MSG:%s ", GREEN, RESET);
	printf("%s%s%s\n", YELLOW, strerror(errno), RESET);
	printf("\n");

	errno = 0;
	fd = 75;
	my_read(fd, 100);
	printf("%sFT_READ ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n", YELLOW, errno, RESET);
	printf("%sFT_READ ERRNO MSG:%s ", GREEN, RESET);
	printf("%s%s%s\n", YELLOW, strerror(errno), RESET);

	printf("\n\n%s*** (enter something two times to test ft_read on stdout) ***%s\n\n", PINK, RESET);

	errno = 0;
	original_read(STDOUT_FILENO, 20);
	printf("   %sREAD ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n\n", YELLOW, errno, RESET);

	errno = 0;
	my_read(STDOUT_FILENO, 20);
	printf("%sFT_READ ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n\n", YELLOW, errno, RESET);
}