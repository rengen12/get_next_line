/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:30:03 by dbuy              #+#    #+#             */
/*   Updated: 2017/11/13 14:30:05 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (ac == 1)
		return (0);
	printf("###############################-START-##################################\n");
	if (!(fd1 = open(av[1], O_RDONLY)))
		return (0);
	if (!(fd2 = open(av[2], O_RDONLY)))
		return (0);


	get_next_line(fd1, &line);
	printf("PRINTED LINE[0] FILE 1:\n");
	ft_putendl(line);

	get_next_line(fd1, &line);
	printf("PRINTED LINE[0] FILE 1:\n");
	ft_putendl(line);

	while ((get_next_line(fd2, &line)) > 0)
	{
		printf("PRINTED LINE[0] FILE 2:\n");
		ft_putendl(line);
	}

	// if ((get_next_line(fd, &line)) != -1)
	// 	ft_putendl(line);	
	close(fd1);
	close(fd2);	
	return (0);
}
