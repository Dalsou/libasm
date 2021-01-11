/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:54:26 by afoulqui          #+#    #+#             */
/*   Updated: 2021/01/11 17:09:21 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	original_write(int fd, const void *buff, size_t count)
{
        ssize_t	ret;

		ret = 0;
        ret = write(fd, buff, count);
        printf("\n   %sWRITE RETURN:%s ", GREEN, RESET);
		printf("%s%ld%s", YELLOW, ret, RESET);
}

void	my_write(int fd,const void *buff, size_t count)
{
        ssize_t	ret;

		ret = 0;
        ret = ft_write(fd, buff, count);
        printf("\n%sFT_WRITE RETURN:%s ", GREEN, RESET);
		printf("%s%ld%s\n", YELLOW, ret, RESET);
}

void	ft_write_test()
{
	int fd;

	printf("\n\n%s*** WRITING A LONG STRING ***%s\n\n", PINK, RESET);

	errno = 0;
	fd = 0;
	if (!(fd = open("tests/txt_files/write.txt", O_RDWR)))
	{
		printf("\n%sError in fd%s\n", RED, RESET);
		return ;
	}
	original_write(fd, LONGSTR, 80);
	close(fd);
	
	errno = 0;
	fd = 0;
	if (!(fd = open("tests/txt_files/ft_write.txt", O_RDWR)))
	{
		printf("\n%sError in fd%s\n", RED, RESET);
		return ;
	}
	my_write(fd, LONGSTR, 80);
	close(fd);

	printf("\n\n%s*** WRITING IN WRONG FD ***%s\n\n", PINK, RESET);
	
	errno = 0;
	original_write(-30, LONGSTR, 73);
	printf("\n   %sWRITE ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n", YELLOW, errno, RESET);
	printf("   %sWRITE ERRNO MSG:%s ", GREEN, RESET);
	printf("%s%s%s\n", YELLOW, strerror(errno), RESET);
	
	errno = 0;
	my_write(-30, LONGSTR, 73);
	printf("%sFT_WRITE ERRNO:%s ", GREEN, RESET);
	printf("%s%d%s\n", YELLOW, errno, RESET);
	printf("%sFT_WRITE ERRNO MSG:%s ", GREEN, RESET);
	printf("%s%s%s\n", YELLOW, strerror(errno), RESET);
	
	printf("\n\n%s*** STDOUT TEST ***%s\n\n", PINK, RESET);
	
	original_write(STDOUT_FILENO, LONGSTR, 40);
	printf("\n");
	
	my_write(STDOUT_FILENO, LONGSTR, 40);
	printf("\n");
}