/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:58:01 by seroy             #+#    #+#             */
/*   Updated: 2023/03/09 13:35:20 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_struct
{
	int		reads;
	char	*buf;
	char	*line;
}				t_struct;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);

#endif