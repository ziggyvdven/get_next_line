/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:13:10 by zvandeven         #+#    #+#             */
/*   Updated: 2023/02/28 17:53:48 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_checkzero(long int a, int fd)
{
	if (a == 0)
	{
		write (fd, "0", 1);
	}
}

int	main()
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		{
			ft_putstr_fd("open() failed failed\n", 1);
		}
	printf("first line = %s\n", get_next_line(fd));
	printf("second line = %s\n", get_next_line(fd));
	printf("second line = %s\n", get_next_line(fd));
	if (close(fd) == -1)
		ft_putstr_fd("close() failed\n", 1);
	return 0;
}
