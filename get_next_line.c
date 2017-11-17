/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengen <rengen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:29:24 by amichak           #+#    #+#             */
/*   Updated: 2017/11/17 11:37:54 by rengen           ###   ########.fr       */
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

void	addfile(int fd, char *line, t_list **files)
{
	size_t	size;
    t_list	*tmp;

	if(*files)
	{
		tmp = *files;
		while (tmp->next && (int)tmp->content_size != fd)
			tmp = tmp->next;
        if ((int)tmp->content_size == fd)
            ft_strdel((char **)(&tmp->content));
        else
            ft_lstadd(files, (tmp = (t_list *)malloc(sizeof(t_list))));
	}
	else
	{
		if (!(*files = (t_list *)malloc(sizeof(t_list))))
			return ;
		tmp = *files;
        tmp->next = NULL;
	}
	tmp->content_size = fd;
	size = ft_strlen(line) + 1;
	tmp->content = ft_strsub(line, size, ft_strlen(line + size));
}
int		get_next_line(const int fd, char **line)
{
	size_t			i;
	static t_list	*files;
    t_list			*file;
	int 			ret;
    size_t 			oldi;

	i = 0;
	if (!line || fd < 0 || fd > 255)
		return (-1);
	if (files)
	{
        //ft_putendl("CHECKING FILES");
		file = files;
		while (file)
		{
			if (fd == (int)file->content_size)
            {
                //while (*((char *)(file->content)) == '\n' && *(file->content + 1) != '\0')
                  //  file->content++;
                i = ft_strlen(file->content);
                break ;
            }
			file = file->next;
		}
        //ft_putendl("CHECKING FILES END");
	}
    if (!(*line = ft_strnew(BUFF_SIZE + i)))
        return (-1);
	ft_bzero(line[0], BUFF_SIZE + i + 1);
	if (i)
    {
        ft_memmove(line[0], file->content, i);
        ft_strdel((char **)(&file->content));
        //ft_memccpy(line[0], file->content, '\n', i);
        i = ft_strlen(line[0]);
        //filedel(&files, file->content_size); not needed
    }

	while (((ret = read(fd, &line[0][i], BUFF_SIZE)) > 0) || i)
	{
		oldi = i;
        i = 0;

        // while (buff[i] == '\n' && !line[0][0])
        //     i++;
        // if (i > 0 && i < BUFF_SIZE)
        //     *line = ft_strcat(*line, ft_strdup(buff + i));
        // else if (i == 0)
             //*line = ft_strcat(*line, ft_strdup(buff));
        // i = 0;
		while (line[0][i] != '\0')
        {
            if (line[0][i] == '\n') //line is over
            {
                line[0][i] = '\0';
                if (((i + 1) % BUFF_SIZE) != 0)
                    addfile(fd, *line, &files); 
                return (1);   
            }
            i++;
            if ((i % (BUFF_SIZE + oldi)) == 0)
                *line = ft_realloc(*line);
        }
	}
    if (i > 0)
        return (1);
	return (ret);
}
