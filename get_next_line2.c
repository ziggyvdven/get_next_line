/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:07:40 by zvandeven         #+#    #+#             */
/*   Updated: 2023/03/07 14:43:38 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*ft_read_line(char *stash, char *buf, int fd)
{
	int		read_nb;

	read_nb = BUFFER_SIZE;
	while (!(ft_strchr(buf, '\n')) && read_nb == BUFFER_SIZE)
	{
		read_nb = read(fd, buf, BUFFER_SIZE);
		if (read_nb == -1)
		{
			free (stash);
			free(buf);
			return (NULL);
		}
		stash = ft_strjoin(stash, buf);
		if (read_nb != BUFFER_SIZE)
		stash = ft_substr(stash, 0, ft_strlen(stash) - (BUFFER_SIZE - read_nb));
	}
	return (stash);
}

char	*make_stash(char *stash, char *buf)
{
	if (stash == NULL)
	{
		stash = (char *)ft_calloc(sizeof(char), ft_strlen(buf) + 1);
		if (!stash)
			return (NULL);
		ft_strlcpy(stash, buf, ft_strlen(buf) + 1);
		return (stash);
	}
	else
	stash = ft_substr(stash, ft_strchr(stash, '\n') + 1, (BUFFER_SIZE));
	return (stash);
}

char	*make_new_line(char *stash)
{
	char	*new_line;

	if (ft_strchr(stash, '\n'))
		new_line = ft_substr(stash, 0, ft_strchr(stash, '\n') + 1);
	else
		new_line = ft_substr(stash, 0, ft_strlen(stash));
	if (!new_line)
		ft_free(new_line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buf)
	{
		buf = ft_free (buf);
		return (NULL);
	}
	stash = make_stash(stash, buf);
	stash = ft_read_line(stash, buf, fd);
	if (!stash || !ft_strlen(stash))
	{
		ft_free (stash);
		return (NULL);
	}
	new_line = make_new_line(stash);
	if (!stash)
		stash = ft_free (stash);
	return (new_line);
}
