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
	int		n;

	n = ft_strlen(str);
	if (!(tmp = (char *)malloc(sizeof(char) * (n + BUFF_SIZE + 1))))
		return (NULL);
	ft_bzero(tmp, n + 1 + BUFF_SIZE);
	ft_memmove(tmp, str, n);
	ft_strdel(&str);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int	i;
	int			ret;
	int size;
	char ch;

	size = BUFF_SIZE;
	i = 0;
	if (!line[0])
		if (!(line[0] = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	ft_bzero(line[0], BUFF_SIZE + 1);
	//write(1, "2\n", 2);
	while ((ret = read(fd, &ch, 1)) > 0)
	{
		line
		if (line[0][i] == '\n')
		{
			line[0][i] = '\0';
			//ft_putendl("bl");
			return (1);
		}
		i++;
		if (size == i)
		{
			//ft_putendl(*line);
			//ft_putstr(" size == i = ");
			//ft_putnbr(i);
			//ft_putendl("");
			line[0] = ft_realloc(line[0]);
			size += i;
			//ft_putendl(*line);

		}
		//write(1, "4\n", 2);
	}
	line[0][i] = '\0';
	printf("finish ret = %d\n", ret);
	return (1);
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
		//printf("res in main = %d\n", res);
		ft_putendl(str);
		res = get_next_line(fd, &str);
		ft_putendl(str);
		// res = get_next_line(fd, &str);
		// ft_putendl(str);
		// res = get_next_line(fd, &str);
		// ft_putendl(str);
		// res = get_next_line(fd, &str);
		// ft_putendl(str);
		close(fd);
	}

	return (0);
}