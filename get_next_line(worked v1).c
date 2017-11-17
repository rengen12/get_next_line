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
#include "libft/libft.h"
#include <stdio.h>

char	*ft_realloc(char *str)
{
	char	*tmp;
	size_t		n;

	n = ft_strlen(str);
	if (!(tmp = (char *)malloc((n + BUFF_SIZE + 1))))
		return (NULL);
	ft_bzero(tmp, n + 1 + BUFF_SIZE);
	ft_memmove(tmp, str, n);
	ft_strdel(&str);
	return (tmp);
}

void	addfile(int fd, char *line, t_nxtl **files)
{
	size_t	size;
	t_nxtl	*tmp;

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
	size = ft_strlen(line);
	tmp->rem = ft_strsub(line, size + 1, ft_strlen(line + size + 1));
	tmp->next = NULL;
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

void    filedel(t_nxtl **head, int fd)
{
    t_nxtl *tmp;
    t_nxtl *tmpprev;

    if (!head)
        return ;
    tmp = *head;
    if (tmp->fd == fd)
    {
        *head = (*head)->next;
        free(tmp);
        return ;
    }
    while (tmp)
    {
        if (tmp->fd == fd)
        {
            tmpprev->next = tmp->next;
            free(tmp);
            return ;
        }
        tmpprev = tmp;
        tmp = tmp->next;
    }
}

int		get_next_line(const int fd, char **line)
{
	size_t			i;
	static t_nxtl	*files;
	t_nxtl			*file;
	int 			ret;
    size_t 			oldi;

	i = 0;
	if (fd < 0 || !line)
		return (-1);
	if (files)
	{
		file = files;
		while (file)
		{
			if (fd == file->fd)
				if (files->rem)
                {
					i = ft_strlen(file->rem);
                    break ;
                }
			file = file->next;
		}
	}
    if (!(*line = (char *)malloc(BUFF_SIZE + i + 1)))
        return (-1);
	ft_bzero(line[0], BUFF_SIZE + i + 1);
	if (i)
    {
        ft_strcat(line[0], file->rem);
        filedel(&files, file->fd);
    }
	while ((ret = read(fd, &line[0][i], BUFF_SIZE)) > 0)
	{
		oldi = i;
		while (i < ret + oldi)
		{
			if (line[0][i] == '\n') //line is over
			{
				line[0][i] = '\0';
				if ((i + 1) % BUFF_SIZE != 0) 
					addfile(fd, *line, &files); // if remainder is exist - write it to struct
				return (1);
			}
			i++;
		}
		if (i % (BUFF_SIZE + oldi) == 0)
        {
            *line = ft_realloc(*line);
        }
	}
	line[0][i] = '\0'; //why?
	return (ret);
}




int		main(int ac, char **av)
{
	int fd, fd1, fd2;
	char *str;
	int res = 0;
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
        fd2 = open(av[3], O_RDONLY);
/*
        ft_putendl("");
		ft_putendl("1_call:");
		ft_putendl("file1 | out1:");
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
		res = get_next_line(fd, &str);
		ft_putendl(str);

        ft_putendl("");
		ft_putendl("2_call:");
		ft_putendl("file2 | out2:");
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
		res = get_next_line(fd1, &str);
		ft_putendl(str);

        ft_putendl("");
		ft_putendl("3_call:");
        ft_putendl("file1 | out3:");
		res = get_next_line(fd, &str);
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
		ft_putendl(str);

        ft_putendl("");
		ft_putendl("4_call:");
		ft_putendl("file2 | out4:");
		res = get_next_line(fd1, &str);
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
		ft_putendl(str);

        ft_putendl("");
        ft_putendl("5_call:");
        ft_putendl("file3 | out5:");
        res = get_next_line(fd2, &str);
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
        ft_putendl(str);
*/
        ft_putendl("");
        ft_putendl("6_call:");
        ft_putendl("file3 | out6:");
        res = get_next_line(fd2, &str);
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
        ft_putendl(str);

        ft_putendl("");
        ft_putendl("7_call:");
        ft_putendl("file3 | out7:");
        res = get_next_line(fd2, &str);
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
        ft_putendl(str);
/*
        ft_putendl("");
        ft_putendl("8_call:");
        ft_putendl("file--- | out8:");
        res = get_next_line(10, &str);
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
        ft_putendl(str);
*/

        close(fd);
		close(fd1);
        close(fd2);
	}
	(void)res;
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
