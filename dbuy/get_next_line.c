/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:46:19 by dbuy              #+#    #+#             */
/*   Updated: 2017/11/13 14:18:23 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

char 	*ft_buff_offset(char *buff)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < BUFF_SIZE && buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		count++;
//	printf("I in buff_offset = %d\n", i);
	if (i != BUFF_SIZE)
	{
		ft_memmove(buff, buff + i + 1, BUFF_SIZE - i);
		buff[BUFF_SIZE - i - 1] = '\0';
	}
	if (i == BUFF_SIZE || count == 0)
		ft_bzero(buff, BUFF_SIZE);
	return (buff);
}

char	*ft_realloc(char *line)
{
//	printf("REALLOC for LINE...\n");
	int 	i;
	char	*buff;

	i = 0;
	while (line[i] != '\0')
		i++;
	if(!(buff = (char*)malloc(i + 1 + BUFF_SIZE)))
		return (NULL);
	ft_bzero(buff, i + 1 + BUFF_SIZE);
	ft_memmove(buff, line, i + 1);
	free(line);
	return (buff);
}

int		ft_convert(char *line, char *buff, int n)
{
	int i;
	int ret;
	int pos;
	int b;

	i = 0;
	ret = 0;
	b = 0;
	// printf("n in convert = %d\n", n);
	printf("BUFF in convert:\n%s$\n", buff);
	printf("LINE[0] in convert:\n%s$\n", line);
	while (line[i] != '\0')
		i++;
	pos = i;
//	printf("pos in convert = %d\n", i);
	while (i < BUFF_SIZE + pos && buff[b] != '\n' && buff[b] != '\0')
	{
		line[i++] = buff[b++];
	}
//	printf("i in convert = %d\n", i);
	line[i] = '\0';
	if (buff[i] == '\n')
		ret = 1;
	if (buff[i] =='\0' && n == 0)
		ret = 0;
	if (i == BUFF_SIZE)
		ret = 2;
	buff = ft_buff_offset(buff);
	if (b == BUFF_SIZE)
		ret = 2;
	printf("BUFF out from convert:\n%s$\n", buff);
	printf("LINE[0] out from convert:\n%s$\n", line);		
	return (ret);
}

void	ft_display(t_files *files)
{
	printf("DISPLAYING FILES:\n");
	int i;

	i = 0;
	while (files)
	{
		printf("files index = %d, fd = %d\n", i, files ->fd);
		files = files->next;
		i++;
	}
}

t_files		*ft_find(t_files *files, const int fd)
{
	// t_files *files;

	// files = tmp;
	while (files && files->active == 1)
	{
		printf("Searching fd...\n");
		printf("Current found fd = %d\n", files->fd);
		if (files->fd == fd)
		{
			printf("fd was found = %d\n", files->fd);
			return (files);
		}
		files = files->next;
	}
	printf("fd was not found, creating new list elem...\n");
	// if (!(files = (t_files*)malloc(sizeof(t_files))))
	// 	return (0);
	if (!files)
		if (!(files = (t_files*)malloc(sizeof(t_files))))
			return (NULL);
	files->next = NULL;
	files->fd = fd;
	files->active = 1;
	puts ("test");
	if (!(files->buff = (char*)malloc(BUFF_SIZE)))
		return (NULL);
	ft_bzero(files->buff, BUFF_SIZE);
	printf("FILES AFTER Making new:\n");	
	ft_display(files);
	return (files);
}

int		get_next_line(const int fd, char **line)
{
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GET LINE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("fd = %d\n", fd);
	static t_files	files;
	t_files			*tmp;
	int				n;
	int				offset;

	ft_display(&files);
	n = -1;
	if (!line || fd < 0)
		return (-1);
	if (!line[0])
		if (!(line[0] = (char*)malloc(BUFF_SIZE + 1)))
			return (-1);
	ft_bzero(line[0], BUFF_SIZE + 1);
	if (!(tmp = ft_find(&files, fd)))
		return (-1);
	// printf("FILES AFTER INITIALISATION:\n");
	// ft_display(&files);
	if ((tmp->buff)[0] != '\0')
	{
		printf("buff not empty!:\n%s$\n", tmp->buff);
		n = ft_convert(line[0], tmp->buff, 0);
		if (n == 1)
		{
			printf(">>>>>>>>>> Nreturning value = 1 <<<<<<<<<<<<\n");			
			return (1);
		}
	}
	while (read(fd, tmp->buff, BUFF_SIZE) > 0)
	{
		printf("Reading file...\n");
		n = ft_convert(line[0], tmp->buff, offset);
		printf("result of convert = %d\n", n);
		if (n == 1)
		{
			printf(">>>>>>>>>> returning value = 1 <<<<<<<<<<<<\n");
			return (1);
		}
		if (n == 0)
		{
			printf(">>>>>>>>>> returning value = 1 <<<<<<<<<<<\n");
			return (1);
		}
		if (n == 2)
		{
			offset = offset + BUFF_SIZE;
			line[0] = ft_realloc(line[0]);
		}

	}
	if (n == -1)
	{
		printf(">>>>>>>>>> returning value = -1 <<<<<<<<<<<<\n");		
		return (-1);
	}
	else
	{
		printf(">>>>>>>>>> returning value = 1 <<<<<<<<<<<\n");
		return (1);
	}
}
