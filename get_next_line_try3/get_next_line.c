/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:43:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/10 18:21:25 by zvan-de-         ###   ########.fr       */
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
			free (buf);
			return (NULL);
		}
		if (read_nb != 0)
			s = ft_strjoin(s, buf, read_nb);
		free(buf);
	}
	return (s);
}

void	ft_make_line(char *s, char **new_line)
{
	int i;
	int j;

	if (s == NULL)
		return ;
	j = 0;
	i = 0;
	*new_line = (char *)ft_calloc(sizeof(char), ft_strchr(s, '\n') + 1);
	if (*new_line == NULL)
		return ;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			(*new_line)[j++] = s[i];
			break ;
		}
	(*new_line)[j++] = s[i++];
	}
}

char	*get_next_line(int fd)
{
	static char		*stash  = NULL;
	char			*nl = NULL;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &nl, 0) < 0)
		return (NULL);
/*1. function that reads a line and put it in a static buffer*/
	stash = ft_readline(stash, fd);
	printf("stash = %s\n", stash);
/*2. function thats creates a newline from the buffer up until it encounters a newline*/
	ft_make_line(stash, &nl);
	printf("new line = %s\n", nl);
	free(nl);
	nl = NULL;
/*3. function that trims the first part from the buffer up until it encounters a newline.*/
	return (nl);
}
