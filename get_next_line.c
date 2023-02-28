/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:07:40 by zvandeven         #+#    #+#             */
/*   Updated: 2023/02/28 17:55:12 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*stash;
	char			*new_line;
	int				start;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buf, BUFFER_SIZE);
	if (buf == stash)
		return (NULL);
	if (stash == NULL)
		stash = ft_strdup(buf);
	else
		stash = ft_strjoin(stash, buf);
	while (ft_checknewline(buf) == BUFFER_SIZE)
	{
		read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
	}
	new_line = ft_substr(stash, 0, ft_checknewline(stash) + 1);
	start = ft_checknewline(stash);
	stash = ft_substr(stash, start + 1, (BUFFER_SIZE - start));
	free (buf);
	return (new_line);
}
