/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:43:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/07 19:58:07 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_make_stash(char *stash, char *buf, int fd)
{
	char	*temp;

	if (stash == NULL)
	{
		stash = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		ft_strlcpy(stash, buf, BUFFER_SIZE + 1);
	}
	if (!ft_strchr(stash, '\n'))
		stash = ft_read_line(stash, buf, fd);
	else if (ft_strchr(stash, '\n'))
	{
		temp = ft_calloc(1, ft_strlen(stash) - ft_strchr(stash, '\n'));
		ft_strlcpy(temp, stash + ft_strchr(stash, '\n'),
			ft_strlen(stash) - ft_strchr(stash, '\n') + 1);
		ft_free (stash);
		return (ft_read_line(temp, buf, fd));
	}	
	if (stash == NULL)
		ft_free(stash);
	return (stash);
}

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
	char	*tmp;

	read_nb = BUFFER_SIZE;
	while (ft_strchr(buf, '\n') == 0 && read_nb == BUFFER_SIZE)
	{
		read_nb = read(fd, buf, BUFFER_SIZE);
		if (read_nb < 0)
		{
			ft_free (buf);
			return (NULL);
		}
		if (read_nb != BUFFER_SIZE)
		{
			tmp = ft_calloc(sizeof(char), read_nb + 1);
			ft_strlcpy(tmp, buf, read_nb + 1);
			stash = ft_strjoin(stash, tmp);
		}
		else
		stash = ft_strjoin(stash, buf);
	}
	return (stash);
}

char	*ft_new_line(char *stash)
{
	char	*new_line;

	if (ft_strchr(stash, '\n'))
	new_line = ft_calloc(sizeof(char), ft_strchr(stash, '\n') + 1);
	else
	new_line = ft_calloc(sizeof(char), ft_strlen(stash) + 1);
	if (!new_line)
		return (NULL);
	if (ft_strchr(stash, '\n'))
		ft_strlcpy(new_line, stash, ft_strchr(stash, '\n') + 1);
	else
	{
		ft_strlcpy(new_line, stash, ft_strlen(stash) + 1);
		ft_free(stash);
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free(buf));
	stash = ft_make_stash(stash, buf, fd);
	ft_free (buf);
	if (ft_strlen(stash) == 0)
		return (NULL);
	return (ft_new_line(stash));
}
