/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:55:29 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/20 19:34:32 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

/* \brief *get_net_line returns a line read from a file descriptor
\param fd file description
\return read line, or NULL for EOF or error. */
char		*get_next_line(int fd);
/* \brief The strchr() function
\return a pointer to the first occurrence of the character c in the string s.*/
char		*ft_strchr(const char *s, int c);
/* \brief The strlcpy() function copies up to size - 1 characters from the
NUL-terminated string src to dst, NUL-terminating the result.*/
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
/* \brief Allocates (with malloc(3)) and returns a substring from the string
’s’. The substring begins at index ’start’ and is of maximum size ’len’.
\return the substring or NULL if the allocation fails.*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
/* \brief Allocates (with malloc(3)) and returns a new string, which is the
result of the concatenation of ’s1’ and ’s2’.
\return the concatenation or NULL if the allocation fails.*/
char		*ft_strjoin(char const *s1, char const *s2);
/* \brief The  strdup() function
\return a pointer to a new string which is a duplicate of the string s.*/
char		*ft_strdup(const char *s);

#endif
