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

	ft_putendl("IN REALLOC");
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

void	addfile(int fd, char **line, t_nxtl **files)
{
	size_t	i;
	size_t	size;
	t_nxtl	*tmp;

	i = 0;
	if(*files)
	{
		tmp = *files;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_nxtl *)malloc(sizeof(t_nxtl))))
			return ;
		tmp = tmp->next;
	}
	else
	{
		if (!(*files = (t_nxtl *)malloc(sizeof(t_nxtl))))
			return ;
		tmp = *files;
	}
	tmp->fd = fd;
	size = ft_strlen(*line);
	tmp->rem = ft_strsub(*line, size + 1, ft_strlen(*line + size + 1));
	tmp->next = NULL;
	// ft_putendl("line:");
	// ft_putendl(line[0]);
	 // ft_putendl("fd:");
	 // ft_putnbr(files.fd);
	// ft_putendl("");
	// ft_putendl("rem:");
	// ft_putendl(files.rem);
	// ft_putendl("IN ADDFILE");
	// ft_putendl(line[0]);
}

/*TEST STRUCT*/
/*void print_files(t_nxtl *files)
{
	int i;

	i = 0;
	if (!files)
	{
		ft_putendl("struct is empry");
		return ;
	}
	while (files)
	{
		ft_putnbr(i++);
		ft_putstr("\nfd = ");
		ft_putnbr(files->fd);
		ft_putstr("\nrem = ");
		ft_putendl(files->rem);
		ft_putendl("END");
		files = files->next;
	}
	
}*/

int		get_next_line(const int fd, char **line)
{
	size_t			i;
	static t_nxtl	*files;
	static t_nxtl	*file;
	size_t 			ret;

	if (fd < 0 || !line)
		return (-1);
	if (!line[0])
		if (!(line[0] = (char *)malloc(BUFF_SIZE + /*ft_strlen(files.rem)*/BUFF_SIZE + 1)))
			return (-1);
	ft_bzero(line[0], BUFF_SIZE + 1);
	i = 0;
	//write(1, "1\n", 2);
	if (files)
	{
		file = files;
		while (file)
		{
			if (fd == file->fd)
			{
				//write(1, "2\n", 2);
				if (files->rem)
				{
					//write(1, "3\n", 2);
					i = ft_strlen(file->rem);
					//ft_putnbr(i);
					ft_strcat(line[0], file->rem);
					//ft_putendl("LINE AFTER STRLCAT:");
					//ft_putendl(line[0]);
				}
			}
			file = file->next;
		}
	}
	while ((ret = read(fd, &line[0][i], BUFF_SIZE)) > 0)
	{
		/*ft_putstr(">>>>>BUFF_SIZE = ");
		ft_putnbr(BUFF_SIZE);
		ft_putstr("\nret = ");
		ft_putnbr(ret);
		ft_putendl("\nafter read");
		ft_putendl(line[0]);*/
		while (i < ret)
		{
			//ft_putendl("in while");
			if (line[0][i] == '\n') //line is over
			{
				/*if (line[0][i] == '\n')
				{
					ft_putendl("BEFORE addfile");
					ft_putendl(line[0]);
				}*/
				line[0][i] = '\0'; //why?
				if ((i + 1) % BUFF_SIZE != 0) 
					addfile(fd, line, &files); // if remainder is exist - write it to struct
				return (1);
			}
			i++;
		}
		if (i % BUFF_SIZE == 0)
			line[0] = ft_realloc(line[0]);
	}
	line[0][i] = '\0'; //why?
	return (0);
}

int		main(int ac, char **av)
{
	int fd, fd1;
	char *str;
	int res;
	/*TESTING STRUCT*/
	/*static t_nxtl *files;
	char *a = "asd\0q111";
	char *b = "zxc\0q222";
	char *c = "qwe\0q333";
	a = malloc(9);
	b = malloc(9);
	c = malloc(9);
	strcpy(a, "asd");
	strcpy(b, "zxc");
	strcpy(c, "qwe");
	a[3] = '\0';
	b[3] = '\0';
	c[3] = '\0';
	a[4] = '1';
	b[4] = '2';
	c[4] = '3';
	a[5] = 't';
	b[5] = 'y';
	c[5] = 'u';
	a[6] = '\0';
	b[6] = '\0';
	c[6] = '\0';*/
	if (ac >= 2)
	{
		fd = open(av[1], O_RDONLY);
		fd1 = open(av[2], O_RDONLY);

		ft_putendl("1_call:");
		ft_putendl("file1 | out1:");
		res = get_next_line(fd, &str);
		ft_putendl(str);

		ft_putendl("2_call:");
		ft_putendl("file2 | out1:");
		res = get_next_line(fd1, &str);
		ft_putendl(str);

		ft_putendl("3_call:");
		res = get_next_line(fd, &str);
		ft_putendl("file1 | out2:");
		ft_putendl(str);

		ft_putendl("4_call:");
		ft_putendl("file2 | out2:");
		res = get_next_line(fd1, &str);
		ft_putendl(str);		





		close(fd);
		close(fd1);
	}
	/*TEST STRUCT*/
	/*addfile(3, &a, &files);
	print_files(files);
	ft_putendl("\nnext try>>>>>>.");
	addfile(4, &b, &files);
	print_files(files);
	ft_putendl("\n22222next try>>>>>>");
	addfile(5, &c, &files);
	print_files(files);*/
	return (0);
}
