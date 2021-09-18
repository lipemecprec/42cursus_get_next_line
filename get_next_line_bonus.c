/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:54:16 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/18 16:33:58 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	read_line(int fd, char **temp_buf, char **static_buf, char **line);
char	*get_line(char **static_buf, char **line);

char	*get_next_line(int fd)
{
	static char	*static_buf[FOPEN_MAX] = {NULL};
	char		*temp_buf;
	char		*line;
	ssize_t		len;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buf)
		return (NULL);
	if (read(fd, temp_buf, 0) < 0)
	{
		free(temp_buf);
		return (NULL);
	}
	if (!static_buf[fd])
		static_buf[fd] = ft_strdup("");
	len = read_line(fd, &temp_buf, &static_buf[fd], &line);
	if (!line && len == 0)
		return (NULL);
	return (line);
}

ssize_t	read_line(int fd, char **temp_buf, char **static_buf, char **line)
{
	char	*temp;
	ssize_t	len;

	len = 1;
	while ((ft_strchr(*static_buf, '\n') == NULL) && len)
	{
		len = read(fd, *temp_buf, BUFFER_SIZE);
		(*temp_buf)[len] = '\0';
		temp = *static_buf;
		*static_buf = ft_strjoin(temp, *temp_buf);
		free(temp);
	}
	free(*temp_buf);
	*temp_buf = NULL;
	*static_buf = get_line(static_buf, line);
	if (**line == '\0')
	{
		free (*line);
		*line = NULL;
	}
	return (len);
}

char	*get_line(char **static_buf, char **line)
{
	size_t	i;
	char	*next_buf;

	i = 0;
	next_buf = NULL;
	while ((*(*static_buf + i) != '\n') && (*(*static_buf + i) != '\0'))
		i++;
	if (*(*static_buf + i) == '\n')
	{
		i++;
		*line = ft_substr(*static_buf, 0, i);
		next_buf = ft_strdup(*static_buf + i);
	}
	else
		*line = ft_strdup(*static_buf);
	free(*static_buf);
	*static_buf = NULL;
	return (next_buf);
}
