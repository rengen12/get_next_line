/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:15:10 by dbuy              #+#    #+#             */
/*   Updated: 2017/11/13 14:17:15 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_files
{
	int				fd;
	int				active;
	char			*buff;
	struct s_files	*next;
}					t_files;

int					get_next_line(const int fd, char **line);
t_files				*ft_find(t_files *files, const int fd);
int					ft_convert(char *line, char *buff, int n);
char				*ft_buff_offset(char *line);
char 				*ft_buff_offset(char *buff);
char				*ft_realloc(char *line);

#endif
