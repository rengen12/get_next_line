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

int		get_next_line(const int fd, char **line)
{
	size_t		i;

	i = 0;
	if (fd < 0 || !line)
		return (-1);
	if (!line[0])
		if (!(line[0] = (char *)malloc(BUFF_SIZE + 1)))
			return (-1);
	ft_bzero(line[0], BUFF_SIZE + 1);
	while (read(fd, &line[0][i], 1) > 0)
	{
		if (line[0][i] == '\n')
		{
			line[0][i] = '\0';
			return (1);
		}
		i++;
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
		ft_putendl(str);
		res = get_next_line(fd, &str);
		ft_putendl(str);
		close(fd);
	}
	return (0);
}