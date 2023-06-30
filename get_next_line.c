/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:57 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/06/30 19:03:20 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Read data from a file into a buffer.*/
char	*read_buffer(int fd, char *buffer, int *buffer_index, int *buffer_size)
{
	if (*buffer_index >= *buffer_size)
	{
		*buffer_size = read(fd, buffer, BUFFER_SIZE);
		*buffer_index = 0;
		if (*buffer_size < 1)
			return (NULL);
	}
	return (buffer);
}

/*Extract a line from a character buffer.*/
char	*extract_line(char *buffer, int *buffer_index, int buffer_size)
{
	char	*line;
	int		line_index;
	char	current_char;
	char	*temp;

	line_index = 0;
	line = NULL;
	while (*buffer_index < buffer_size)
	{
		current_char = buffer[(*buffer_index)++];
		if (current_char == '\n')
			break ;
		temp = ft_realloc(line, (line_index + 2) * sizeof(char));
		if (!temp)
		{
			free (line);
			return (NULL);
		}
		line = temp;
		line[line_index++] = current_char;
		line[line_index] = '\0';
	}
	return (line);
}

/*v = variable, buf = get buffer,
reads data from a buffer,
extracts a line from it,
and handles cases where partial
lines are read by storing the remaining buffer data in a linked list.
*/
char	*process_buffer(t_var *v)
{
	char	*buf;
	char	*line;
	t_list	*new_node;

	buf = read_buffer(v->fd, v->buffer, &(v->buffer_index), &(v->buffer_size));
	if (!buf)
		return (NULL);
	line = extract_line(buf, &(v->buffer_index), v->buffer_size);
	if (!line)
	{
		ft_free_node_mem(v->start);
		return (NULL);
	}
	if (v->buffer_index < v->buffer_size)
	{
		new_node = ft_lst_new_node (&(v->buffer[v->buffer_index]));
		if (!new_node)
		{
			free (line);
			ft_free_node_mem(v->start);
			return (NULL);
		}
		ft_lst_append_node (&(v->start), &(v->last), new_node);
	}
	return (line);
}

/*Check if the function is being called with a different file descriptor
free node memory and reset buffer
Check if there are any remaining lines in the list*/
char	*get_next_line(int fd)
{
	static t_var	v = {0};
	t_list			*temp;
	char			*line;

	if (fd != v.fd)
	{
		ft_free_node_mem(v.start);
		v.buffer_index = 0;
		v.buffer_size = 0;
		v.fd = fd;
	}
	if (v.start)
	{
		temp = v.start;
		v.start = v.start->next;
		line = temp->line;
		free (temp);
		return (line);
	}
	return (process_buffer(&v));
}
/*
int	main()
{
	int fd;

	fd = open("sample.txt", O_RDWR);
	if (fd == -1)
	{
	perror("Failed to open the file");
	return (1);
	}
	printf("line:%s", get_next_line(fd));
	return(0);
}
*/
