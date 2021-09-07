/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:55:29 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/05 22:01:07 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

/* \brief *get_net_line returns a line read from a file descriptor
\param fd file description
\return read line, or NULL for EOF or error. */
char	*get_next_line(int fd);

#endif
