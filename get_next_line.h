/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:30:00 by amichak           #+#    #+#             */
/*   Updated: 2017/11/11 17:34:09 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 15

typedef struct	s_nxtl
{
	char		*rem;
	int			fd;
	struct s_nxtl *next;
}				t_nxtl;

int		get_next_line(const int fd, char **line);

#endif
