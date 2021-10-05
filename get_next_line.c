/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:54:16 by faguilar          #+#    #+#             */
/*   Updated: 2021/10/05 00:30:09 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **st_buf, char **line)
{
	size_t	i;
	char	*next_buf;

	i = 0;
	next_buf = NULL;
	while ((*(*st_buf + i) != '\n') && (*(*st_buf + i) != '\0'))
		i++;
	if (*(*st_buf + i) == '\n')
	{
		i++;
		*line = ft_substr(*st_buf, 0, i);
		next_buf = ft_strdup(*st_buf + i);
	}
	else
		*line = ft_strdup(*st_buf);
	free(*st_buf);
	*st_buf = NULL;
	return (next_buf);
}

static ssize_t	read_line(int fd, char **temp_buf, char **st_buf, char **line)
{
	char	*temp;
	ssize_t	len;

	len = 1;
	while ((ft_strchr(*st_buf, '\n') == NULL) && len)
	{
		len = read(fd, *temp_buf, BUFFER_SIZE);
		(*temp_buf)[len] = '\0';
		temp = *st_buf;
		*st_buf = ft_strjoin(temp, *temp_buf);
		free(temp);
	}
	free(*temp_buf);
	*temp_buf = NULL;
	*st_buf = get_line(st_buf, line);
	if (**line == '\0')
	{
		free (*line);
		*line = NULL;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*st_buf = NULL;
	char		*temp_buf;
	char		*line;
	ssize_t		len;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buf)
		return (NULL);
	if (read(fd, temp_buf, 0) < 0)
	{
		free(temp_buf);
		return (NULL);
	}
	if (!st_buf)
		st_buf = ft_strdup("");
	len = read_line(fd, &temp_buf, &st_buf, &line);
	if (!line && len == 0)
		return (NULL);
	return (line);
}
