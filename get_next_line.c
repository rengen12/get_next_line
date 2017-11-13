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

char	*ft_realloc(char *str, size_t n)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (n + BUFF_SIZE))))
		return (NULL);
	ft_strncpy(tmp, str, n);

	ft_strdel(&str);
	//ft_putendl("IN REALLOC");
	//ft_putendl(tmp);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int	i;
	int			ret;
	int size;
	size = 0;
	//int			ii;
	size = BUFF_SIZE;
	i = 0;
	//write(1, "1\n", 2);
	//ft_putendl(*line);
	ft_bzero(line, i);
	if (!(*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	//write(1, "2\n", 2);
	while ((ret = read(fd, &line[0][i], 1)) > 0)
	{
		//printf("ret = %d\ni = %d\n", ret, i);
		//write(1, "3 in while\nchar = ", 18);
		//ft_putchar(line[0][i]);
		//write(1, "\n", 1);
		if (line[0][i] == '\n')
		{
			
			line[0][i] = '\0';
			i++;
			ft_putendl("bl");
			return (1);
		}
		if (line[0][i] == '\0')
		{
			
			line[0][i] = '\0';
			i++;
			ft_putendl("eof");
			return (0);
		}
		if (size == i)
		{
			//ft_putendl(*line);
			ft_putstr(" size == i = ");
			ft_putnbr(i);
			ft_putendl("");
			*line = ft_realloc(*line, i);
			size += i;
			ft_putendl(*line);
			ft_putendl(*line);

		}
		i++;
		line[0][i] = '\0';
		//write(1, "4\n", 2);
	}
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
	}
	return (0);
}