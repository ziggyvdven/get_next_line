/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:07:40 by zvandeven         #+#    #+#             */
/*   Updated: 2023/03/01 17:33:49 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

// char	make_new_line(char stash)
// {
// 	char *new_line;

// }

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	int			read_nb;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_nb = BUFFER_SIZE;
	if (stash == NULL)
		stash = ft_strdup(buf);
	while (!(ft_strchr(stash, '\n')) && read_nb == BUFFER_SIZE)
	{
		read_nb = read(fd, buf, BUFFER_SIZE);
		if (read_nb == -1)
		{
			free(buf);
			return (NULL);
		}
		if (read_nb != 0)
		stash = ft_strjoin(stash, buf);
	}
	if (ft_strchr(stash, '\n'))
		new_line = ft_substr(stash, 0, ft_checknewline(stash) + 1);
	else
		new_line = ft_substr(stash, 0, ft_strlen(stash) - BUFFER_SIZE + read_nb + 1);
	stash = ft_substr(stash, ft_checknewline(stash) + 1, (BUFFER_SIZE));
	free (buf);
	if (read_nb <= 0 && !ft_strlen(stash))
		return (NULL);
	return (new_line);
}
