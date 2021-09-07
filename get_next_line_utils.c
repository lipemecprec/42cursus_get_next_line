/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:55:32 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/07 12:41:46 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb * size < 0)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

size_t	ft_linelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	if (s[i] != '\n')
		i++;
	return (i);
}

char	*memincrease(const void *src, size_t size)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * size);
	ft_memmove(dest, src, size);
	free(src);
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destc;
	unsigned char	*srcc;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	destc = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	i = 1;
	if (dest > src)
	{
		while (i <= n)
		{
			destc[n - i] = srcc[n - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	res;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
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
		dst[dst_len] = '\0';
		return (res);
	}
	else
		return (src_len + dstsize);
}

