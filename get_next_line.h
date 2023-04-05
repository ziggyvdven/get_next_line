/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:42:38 by zvandeven         #+#    #+#             */
/*   Updated: 2023/03/14 11:01:07 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_make_line(char *s, char *nl);
char	*ft_stash(char *stash_ptr);
char	*ft_readline(char *s, int fd);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2, int r);
int		ft_strchr(const char *s, int c);
int		ft_strlcpy(char *dst, char *src, int dstsize);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_free(char *s);

#endif