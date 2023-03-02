/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:07:40 by zvandeven         #+#    #+#             */
/*   Updated: 2023/03/02 17:16:16 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(str))
		return (NULL);
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	if (str[0] == '\0')
		free (str);
	return (str);
}

char	*ft_read_line(char *stash, char *buf, int fd)
{
	int		read_nb;

	read_nb = BUFFER_SIZE;
	while (!(ft_strchr(stash, '\n')) && read_nb == BUFFER_SIZE)
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

char	*make_new_line(char *stash)
{
	char	*new_line;

	if (ft_strchr(stash, '\n'))
		new_line = ft_substr(stash, 0, ft_checknewline(stash) + 1);
	else
		new_line = ft_substr(stash, 0, ft_strlen(stash));
	if (!new_line)
		free(new_line);
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
		return (NULL);
	if (stash == NULL)
		stash = ft_strdup(buf);
	if (!stash)
		free(stash);
	stash = ft_read_line(stash, buf, fd);
	if (!stash || !ft_strlen(stash))
	{
		free (stash);
		return (NULL);
	}
	free (buf);
	new_line = make_new_line(stash);
	stash = ft_substr(stash, ft_checknewline(stash) + 1, (BUFFER_SIZE));
	if (!stash)
		free (stash);
	return (new_line);
}
