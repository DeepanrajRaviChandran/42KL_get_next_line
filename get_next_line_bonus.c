/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:12:13 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/02 17:11:06 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	int		size;
	int		index;
}				t_buf;

typedef struct s_node
{
	int				fd;
	t_buf			buf;
	struct s_node	*next;
}				t_node;

t_node	*get_node(t_node **head, int fd)
{
	t_node	*current = *head;

	while (current)
	{
		if (current->fd == fd)
			return current;
		current = current->next;
	}

	current = (t_node *)malloc(sizeof(t_node));
	if (!current)
		return NULL;

	current->fd = fd;
	current->buf.size = 0;
	current->buf.index = 0;
	current->next = NULL;

	if (*head)
	{
		t_node *last = *head;
		while (last->next)
			last = last->next;
		last->next = current;
	}
	else
	{
		*head = current;
	}

	return current;
}

void	remove_node(t_node **head, int fd)
{
	t_node	*current = *head;
	t_node	*prev = NULL;

	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			free(current);
			break;
		}
		prev = current;
		current = current->next;
	}
}

int	read_buffer(int fd, t_buf *buf)
{
	buf->size = read(fd, buf->buf, BUFFER_SIZE);
	buf->index = 0;
	return buf->size;
}

int	append_line(char **line, int *line_index, char current_char)
{
	char	*new_line;

	new_line = realloc(*line, (*line_index + 1) * sizeof(char));
	if (!new_line)
	{
		free(*line);
		return (-1);
	}
	*line = new_line;
	(*line)[(*line_index)++] = current_char;
	return (0);
}

void	finalize_line(char **line, int line_index)
{
	char	*new_line;

	new_line = realloc(*line, (line_index + 1) * sizeof(char));
	if (!new_line)
	{
		free(*line);
		*line = NULL;
	}
	else
	{
		*line = new_line;
		(*line)[line_index] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static t_node	*head = NULL;
	t_node			*current;
	char			*line;
	int				line_index;
	char			current_char;

	current = get_node(&head, fd);
	if (!current)
		return (NULL);

	line = NULL;
	line_index = 0;
	while (1)
	{
		if (current->buf.index >= current->buf.size)
		{
			if (read_buffer(fd, &(current->buf)) <= 0)
			{
				remove_node(&head, fd);
				break ;
			}
		}
		current_char = current->buf.buf[current->buf.index++];
		if (append_line(&line, &line_index, current_char) != 0)
			return (NULL);
		if (current_char == '\n')
			break ;
	}
	if (line == NULL && line_index == 0)
		return (NULL);
	finalize_line(&line, line_index);
	return (line);
}
