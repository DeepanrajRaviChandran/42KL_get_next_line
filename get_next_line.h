/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:06:45 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/06/30 12:07:13 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct s_var
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		buffer_index;
	int		buffer_size;
	t_list	*start;
	t_list	*last;
}			t_var;

char		*get_next_line(int fd);

/*Utility Functions*/
t_list		*ft_lst_new_node(char *line);
void		ft_lst_append_node(t_list **start, t_list **last, t_list *node);
void		ft_free_node_mem(t_list *start);
void		*ft_realloc(void *ptr, size_t size);

#endif
