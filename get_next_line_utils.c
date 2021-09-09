/* ************************************************************************** */
/*										*/
/*							:::	  ::::::::   */
/*   get_next_line_utils.c				  :+:	  :+:	:+:   */
/*							+:+ +:+	 +:+	 */
/*   By: faguilar <faguilar@student.42sp.org.br>	+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2021/09/05 21:55:32 by faguilar	  #+#	#+#		 */
/*   Updated: 2021/09/08 23:55:30 by faguilar	 ###   ########.fr	   */
/*										*/
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	isline(char *buf, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (buf && buf[i] != '\n' && buf[i] != '\0' && i < size)
		i++;
	if (buf[i] != '\n' || buf[i] != '\0')
		return (i);
	return (0);
}

size_t  ft_strlcat(char *dst, char *src, size_t dstsize)
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
		dst[dst_len] = '\0';
		return (res);
	}
	else
		return (src_len + dstsize);
}
