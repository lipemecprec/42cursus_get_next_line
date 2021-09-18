/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:00:41 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/18 01:02:48 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

char	*gnl(int fd);

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		i;
	char	*line;

	fd1 = open("dummy.txt", O_RDONLY);
	fd2 = open("dummy2.txt", O_RDONLY);
	fd3 = open("dummy3.txt", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("fd1 > %s\n", line);
		free (line);
		line = get_next_line(fd2);
		printf("fd2 > %s\n", line);
		free (line);
		line = get_next_line(fd3);
		printf("fd3 > %s\n", line);
		free (line);
		i++;
	}
}
