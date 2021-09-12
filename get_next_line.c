/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:54:16 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/12 11:47:50 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*static_buffer = 0;
	char		*temp_buffer;
	char		*line;
	char		*f_read;
	ssize_t 	len;

	if (0 >= fd || fd >= FOPEN_MAX || BUFFER_SIZE == 0)
		return (NULL);
	temp_buffer = (char *)ft_calloc(sizeof(char), 9999999);
	f_read = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	line = NULL;
	while(1)
	{
		if (!static_buffer)
		{
			read(fd, f_read, BUFFER_SIZE);
			ft_strlcat(temp_buffer, f_read, 9999999);
		}
		else
		{
			temp_buffer = ft_substr(static_buffer, 0, BUFFER_SIZE);
		}
		len = isline(temp_buffer);
		if(len >= 0)
		{
			line = (char *)ft_calloc(sizeof(char), (len + 1));
			line = ft_substr(temp_buffer, 0, len);
			if(temp_buffer[len] != '\0')
			{
				temp_buffer = ft_substr(temp_buffer, len, BUFFER_SIZE - len);
				if (temp_buffer)
					static_buffer = ft_substr(temp_buffer, 0, BUFFER_SIZE - len);
			}
			free(temp_buffer);
			free(f_read);
			return (line);
		}
		else
		{
			static_buffer = NULL;
		}
	}
}
