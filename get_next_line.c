/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:43:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/13 16:33:00 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(char *s, int fd)
{
	char	*buf;
	int		read_nb;

	read_nb = 1;
	buf = NULL;
	while (!ft_strchr(s, '\n') && read_nb != 0)
	{
		buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		read_nb = read(fd, buf, BUFFER_SIZE);
		if ((s == NULL && read_nb == 0) || read_nb == -1)
		{
			ft_free(s);
			return (ft_free(buf));
		}
		if (read_nb != 0)
			s = ft_strjoin(s, buf, read_nb);
		free(buf);
	}
	return (s);
}

char	*ft_make_line(char *s, char *nl)
{
	int		i;
	int		j;
	char	*new_line;

	if (s == NULL)
		return (NULL);
	j = 0;
	i = 0;
	if (ft_strchr(s, '\n'))
		new_line = (char *)ft_calloc(sizeof(char), ft_strchr(s, '\n') + 1);
	else
		new_line = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (new_line == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			new_line[j++] = s[i];
			break ;
		}
	new_line[j++] = s[i++];
	}
	free (nl);
	return (new_line);
}

char	*ft_stash(char *stash_ptr)
{
	int		i;
	int		j;
	char	*s;
	int		len;

	len = ft_strlen(stash_ptr);
	s = (char *)ft_calloc(sizeof(char), len - ft_strchr(stash_ptr, '\n') + 1);
	if (s == NULL || stash_ptr == NULL)
		return (ft_free(s));
	i = 0;
	while (stash_ptr[i] && stash_ptr[i] != '\n')
		i++;
	if (stash_ptr[i] && stash_ptr[i] == '\n')
		i++;
	j = 0;
	while (stash_ptr[i])
		s[j++] = stash_ptr[i++];
	if (ft_strlen(s) == 0)
		return (ft_free(s));
	return (s);
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

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*nl;
	char			*tmp;

	nl = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (read(fd, nl, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (stash);
	}
	tmp = ft_readline(stash, fd);
	nl = ft_make_line(tmp, nl);
	stash = ft_stash(tmp);
	free(tmp);
	tmp = NULL;
	return (nl);
}
