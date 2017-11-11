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

int		get_next_line(const int fd, char **line)
{
	static int	i;
	int			ret;

	ret = 0;
	while ((ret = read(fd, )))
	return ();
}

int		main(int ac, char **av)
{
	int fd;
	char *str;

	if (ac == 2)
	{
		fd = open(av[1], RD_ONLY);
	}
	get_next_line(fd, &str);
	retunr (0);
}