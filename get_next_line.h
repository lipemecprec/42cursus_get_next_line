/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:55:29 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/12 11:26:56 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>

/* \brief *get_net_line returns a line read from a file descriptor
\param fd file description
\return read line, or NULL for EOF or error. */
char	*get_next_line(int fd);
ssize_t	isline(char *buf);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_realloc(void *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *s, int c, size_t n);

#endif
