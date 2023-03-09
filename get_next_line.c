/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:43:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/03/09 17:48:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* function thats creates the stash if it is the first time the function is 
	called. otherwise it checks if there is a new line in the stash and then 
	eiteher read the file or creates a stash if its the end of the file	*/

char	*ft_make_stash(char *stash, int fd)
{
	char	*temp;

	temp = NULL;
	if (!ft_strchr(stash, '\n'))
		return (ft_read_line(stash, fd));
	else if (ft_strchr(stash, '\n'))
	{
		temp = ft_calloc(1, ft_strlen(stash) - ft_strchr(stash, '\n'));
		ft_strlcpy(temp, stash + ft_strchr(stash, '\n'),
			ft_strlen(stash) - ft_strchr(stash, '\n') + 1);
		return (ft_read_line(temp, fd));
	}	
	if (stash == NULL)
		ft_free(stash);
	return (stash);
}

/* function thats frees allocated memory and then sets the pointer to zero.*/

char	*ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

/* function that reads a line and put what it has read in a buffer that 
 * it later joins to the stash it stops whe there is a newline or it is the 
 * end of the file*/

char	*ft_read_line(char *stash, int fd)
{
	int		read_nb;
	char	*tmp;
	char	*buf;

	read_nb = BUFFER_SIZE;
	tmp = NULL;
	while (ft_strchr(stash, '\n') == 0 && read_nb == BUFFER_SIZE)
	{
		buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		read_nb = read(fd, buf, BUFFER_SIZE);
		if (read_nb < 0)
			return (ft_free(buf));
		if (read_nb == 0 && !stash)
			return (NULL);
		if (read_nb != BUFFER_SIZE && read_nb != 0)
		{
			tmp = ft_calloc(sizeof(char), read_nb + 1);
			ft_strlcpy(tmp, buf, read_nb + 1);
			stash = ft_strjoin(stash, tmp);
			free (tmp);
		}
		else if (read_nb != 0)
			stash = ft_strjoin(stash, buf);
		free (buf);
	}
	return (stash);
}

/* function thats allocates memory for the new_line and fills it from the stash 
 * up to \n when at the end of the file it frees the stash */

char	*ft_new_line(char *stash)
{
	char	*line;

	if (ft_strchr(stash, '\n'))
	line = ft_calloc(sizeof(char), ft_strchr(stash, '\n') + 1);
	else
	line = ft_calloc(sizeof(char), ft_strlen(stash) + 1);
	if (ft_strchr(stash, '\n'))
		ft_strlcpy(line, stash, ft_strchr(stash, '\n') + 1);
	else
		ft_strlcpy(line, stash, ft_strlen(stash) + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char 			*new_line;

	new_line = NULL;
	if (ft_strchr(stash, '\n') != 0)
		return (new_line = ft_new_line(stash), stash = ft_make_stash(stash, fd), new_line);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_make_stash(stash, fd);
	if (!stash)
		return (NULL);
	new_line = ft_new_line(stash);
	if (new_line[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (new_line);
}
