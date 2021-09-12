/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:54:16 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/12 17:52:31 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
ssize_t	read_line(int fd, char **temp_buf, char **static_buf, char **line);

char *get_next_line(int fd)
{
	static char	*static_buf = 0;
	char		*temp_buf;
	char		*line;
	char		*f_read;
	ssize_t 	len;

	if (0 >= fd || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while(1)
	{
		if (static_buf == NULL)
		{
			f_read = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
			read(fd, f_read, BUFFER_SIZE);
			f_read[BUFFER_SIZE] = '\0';
			temp_buf = ft_strjoin(temp_buf, f_read);
			free(f_read);
		}
		else
		{
			temp_buf = ft_substr(static_buf, 0, BUFFER_SIZE);
			free(static_buf);
			static_buf = NULL;
		}
		len = isline(temp_buf);
		if(len >= 0)
		{
			line = ft_substr(temp_buf, 0, len);
			static_buf = ft_substr(temp_buf, len, BUFFER_SIZE - len);
			free(temp_buf);
			return (line);
		}
	}
}

// ssize_t	read_line(int fd, char **temp_buf, char **static_buf, char **line)
// {

// }
