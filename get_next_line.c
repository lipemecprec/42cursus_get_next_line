/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:54:16 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/11 17:50:46 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*static_buffer = 0;
	char		*frag;
	char		*line;
	ssize_t		len_read;
	ssize_t		len_frag;
	ssize_t		i;

	frag = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	i = 0;
	line = NULL;
	while (i <= 10)
	{
		if (!static_buffer)
		{
			len_read = read(fd, frag, BUFFER_SIZE);
			len_frag = isline(frag, BUFFER_SIZE);
		}
		else
		{
			ft_strlcpy(frag, static_buffer, BUFFER_SIZE);
			printf("2 - frag == %s\n", frag);
			len_frag = isline(frag, BUFFER_SIZE);
			// static_buffer = 0;
			static_buffer = ft_substr(frag, len_frag + 1, BUFFER_SIZE - len_frag);
			// printf("3 - line == %s\n", line);
		}
		if (len_frag < 0)
		{
			printf("2 - line == %s\n", line);
			line = (char *)ft_realloc(line, sizeof(char) * BUFFER_SIZE * (i + 1));
			printf("2 - line == %s\n", line);
			ft_strlcat(line, frag, BUFFER_SIZE * (i + 1) + 1, '\0');
			printf("2 - line == %s\n", line);
		}
		else
		{
			// printf("3 - line == %s\n", line);
			line = (char *)ft_realloc(line, sizeof(char) * BUFFER_SIZE * (i + 1));
			// printf("3 - line == %s\n", line);
			ft_strlcat(line, frag, BUFFER_SIZE * (i) + len_frag + 1, frag[len_frag]);
			static_buffer = ft_substr(frag, len_frag + 1, BUFFER_SIZE - len_frag);
			printf("ender  == %d\n", frag[len_frag]);
			printf("static == %s\n", static_buffer);
			// printf("3 - line == %s\n", line);
			return (line);
		}
		i++;
	}
	return (line);
}
