/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:06:45 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/07 10:47:33 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX_FD 1024

typedef struct s_buf
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		index;
	int		size;
}			t_buf;

/*Utility Function*/
void	*ft_realloc(void *ptr, size_t size);

char	*get_next_line(int fd);

#endif
