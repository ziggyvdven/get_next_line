/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:57:00 by seroy             #+#    #+#             */
/*   Updated: 2023/03/02 15:07:02 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*ft_over(char *s)
{
	int		i;
	int		j;
	char	*temp;

	if (!s || ft_strlen(s) - ft_strchr(s, '\n') == 0)
	{
		free(s);
		return (NULL);
	}
	temp = ft_calloc((ft_strlen(s) - ft_strchr(s, '\n') + 1), sizeof(char));
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	i = ft_strchr(s, '\n');
	j = 0;
	while (s[i])
		temp[j++] = s[i++];
	free(s);
	return (temp);
}

char	*ft_reads(int fd, int reads, char *buf, char *over)
{
	while (reads != 0 && ft_strchr(buf, '\n') == 0)
	{
		reads = read(fd, buf, BUFFER_SIZE);
		if (reads == -1 || BUFFER_SIZE == 0)
		{
			free(buf);
			free(over);
			over = NULL;
			return (NULL);
		}
		buf[reads] = '\0';
		over = ft_strjoin(over, buf);
	}
	return (over);
}

char	*ft_new_line(char *over)
{
	char	*line;

	line = ft_calloc((ft_strchr(over, '\n') + 1), sizeof(char));
	ft_strlcpy(line, over, (ft_strchr(over, '\n') + 1));
	return (line);
}

char	*get_next_line(int fd)
{
	t_struct		gnl;
	static char		*over;

	gnl.reads = 1;
	gnl.line = NULL;
	if (ft_strchr(over, '\n') != 0)
		return (gnl.line = ft_new_line(over), over = ft_over(over), gnl.line);
	gnl.buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!gnl.buf)
		return (ft_free(gnl.buf));
	over = ft_reads(fd, gnl.reads, gnl.buf, over);
	if (gnl.reads == -1 || BUFFER_SIZE == 0 || !over)
		return (NULL);
	if (ft_strchr(over, '\n'))
		gnl.line = ft_calloc((ft_strchr(over, '\n') + 1), sizeof(char));
	else
		gnl.line = ft_calloc((ft_strlen(over) + 1), sizeof(char));
	ft_strlcpy(gnl.line, over, (ft_strlen(over) + 1));
	free(over);
	over = ft_over(gnl.buf);
	if (!*gnl.line)
		return (ft_free(gnl.line));
	return (gnl.line);
}
