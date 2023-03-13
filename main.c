/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:13:10 by zvandeven         #+#    #+#             */
/*   Updated: 2023/03/13 16:51:27 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
			fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("open() failed\n", 1);
		}
		printf("first line = %s\n", get_next_line(fd));
		printf("second line = %s\n", get_next_line(fd));
		printf("third line = %s\n", get_next_line(fd));
		printf("fourth line = %s\n", get_next_line(fd));
		printf("fifth line = %s\n", get_next_line(fd));
		printf("sixth line = %s\n", get_next_line(fd));
		if (close(fd) == -1)
			ft_putstr_fd("close() failed\n", 1);
	}
	if (argc > 2)
		printf("Too many arguments!");
	return (0);
}
