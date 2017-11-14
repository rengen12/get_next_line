/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:29:24 by amichak           #+#    #+#             */
/*   Updated: 2017/11/11 17:36:59 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_realloc(char *str)
{
	char	*tmp;
	size_t		n;

	n = ft_strlen(str);
	//ft_putendl("INPUT");
	//ft_putendl(str);
	if (!(tmp = (char *)malloc((n + BUFF_SIZE + 1))))
		return (NULL);
	ft_bzero(tmp, n + 1 + BUFF_SIZE);
	ft_memmove(tmp, str, n);
	ft_strdel(&str);
	return (tmp);
}

void	addfile(int fd, char **line, t_nxtl files)
{
	size_t	i;
	size_t	size;

	i = 0;
	files.fd = fd;
	size = ft_strlen(line[0]);
	files.rem = ft_strsub(line[0], size + 1, ft_strlen(line[0] + size + 1));
	// ft_putendl("line:");
	// ft_putendl(line[0]);
	// ft_putendl("fd:");
	// ft_putnbr(files.fd);
	// ft_putendl("");
	// ft_putendl("rem:");
	// ft_putendl(files.rem);
}

int		get_next_line(const int fd, char **line)
{
	size_t			i;
	static t_nxtl	files;

	if (fd < 0 || !line)
		return (-1);
	if (!line[0])
		if (!(line[0] = (char *)malloc(BUFF_SIZE + 1)))
			return (-1);
	ft_bzero(line[0], BUFF_SIZE + 1);
	i = 0;
	while (read(fd, line[0], BUFF_SIZE) > 0)
	{
		ft_putendl("after read");
		ft_putendl(line[0]);
		while (i < BUFF_SIZE)
		{
			ft_putendl("in while");
			if (line[0][i] == '\n')
			{
				ft_putendl("BEFORE addfile");
				ft_putendl(line[0]);
				line[0][i] = '\0';
				if ((i + 1) % BUFF_SIZE != 0)
					addfile(fd, line, files);
				return (1);
			}
			i++;
		}
		if (i % BUFF_SIZE == 0)
			line[0] = ft_realloc(line[0]);
	}
	line[0][i] = '\0';
	return (0);
}

int		main(int ac, char **av)
{
	int fd;
	char *str;
	int res;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		res = get_next_line(fd, &str);
		ft_putendl("out1:");
		ft_putendl(str);
		ft_putendl("out2:");
		res = get_next_line(fd, &str);
		ft_putendl(str);
		close(fd);
	}
	return (0);
}