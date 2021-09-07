/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:54:16 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/07 12:39:59 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

size_t	ft_linelen(const char *s);

char *get_next_line(int fd)
{
	char 			*buf;
	char 			*res;
	static size_t	last = 0;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE);
	res = (char *)ft_calloc(sizeof(char), BUFFER_SIZE);
	while (buf[0] != '\n')
	{
		// printf("fd > %d ", fd);
		read(fd, buf, BUFFER_SIZE);
		if(ft_linelen(buf) == BUFFER_SIZE)
		{
			res = memincrease(buf, BUFFER_SIZE * 2);

		}

		printf("ls > %ld ", lseek(fd, 0, 1));
		printf("char > %s\n", buf);
	}
	return (buf);
}
