/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:15:27 by zvandeven         #+#    #+#             */
/*   Updated: 2023/03/02 12:05:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	int		i;
	char	*ptr;

	i = 0;
	len = 0;
	ptr = (char *)s;
	while (ptr[len] != '\0')
	len++;
	dest = (char *)malloc(len + 1);
	if (!(dest))
		return (NULL);
	while (ptr[i] != '\0')
	{
		dest[i] = ptr[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

int	ft_checknewline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (NULL);
	while (len--)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
