/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:54:16 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/09 00:47:34 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*d_buffer = { 0 };
	char		*frag;
	char		*line;
	ssize_t		len_read;
	ssize_t		len_frag;
	ssize_t		i;

	d_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	frag = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	i = 0;
	while (i <= 10)
	{
		len_read = read(fd, frag, BUFFER_SIZE);
		printf("len_real > %ld\n", len_read);
		// printf("frag > %s\n", frag);
		len_frag = isline(frag, BUFFER_SIZE * (i + 1));
		printf("len_flag > %ld\n", len_frag);
		if (len_frag > 0)
		{
			line = (char *)malloc(sizeof(char) * len_frag + 1);
			ft_strlcat(line, frag, len_frag + 1);
			i = 11;
		}
			ft_strlcat(line, frag, BUFFER_SIZE * i + len_frag + 1);
		i++;
	}

	return (line);
}
