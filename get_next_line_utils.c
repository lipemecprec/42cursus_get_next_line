/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:06:10 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/11 17:41:02 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb * size < 0)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	// ft_bzero(arr, nmemb * size);
	return (arr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return (-1);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

ssize_t	isline(char *buf, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (buf && buf[i] != '\n' && buf[i] != '\0' && i <= size)
		i++;
	if (buf[i] == '\n' || i != size)
		return (i);
	return (-1);
}

size_t  ft_strlcat(char *dst, char *src, size_t dstsize, char end_char)
{
	size_t  i;
	size_t  dst_len;
	size_t  src_len;
	size_t  res;

	dst_len = isline(dst, dstsize);
	src_len = isline(src, dstsize);
	i = 0;
	if (dstsize > dst_len)
	{
		res = dst_len + src_len;
		while ((src[i] != '\0') && (dst_len < (dstsize - 1)))
		{
			dst[dst_len] = src[i];
			i++;
			dst_len++;
		}
		dst[dst_len] = end_char;
		dst[dst_len + 1] = '\0';
		return (res);
	}
	else
		return (src_len + dstsize);
}

void	*ft_realloc(void *src, size_t size)
{
	unsigned char	*dest;
	unsigned char	*srcc;
	size_t			i;
	size_t			len;

	if (size < 1)
	{
		free(src);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	srcc = (unsigned char *)src;
	i = 0;
	while (i < size && src)
	{
		dest[i] = srcc[i];
		i++;
	}
	free (src);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	remmsub;

	if (!s)
		return (NULL);
	remmsub = ft_strlen(s) - start;
	if (start < ft_strlen(s))
	{
		if (remmsub > len)
			sub = (char *)ft_calloc(sizeof(char), len + 1);
		else
			sub = (char *)ft_calloc(sizeof(char), remmsub + 1);
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, &s[start], len + 1);
	}
	else
		sub = (char *)ft_calloc(1, 1);
	return (sub);
}

