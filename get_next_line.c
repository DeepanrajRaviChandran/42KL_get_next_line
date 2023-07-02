/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:12:13 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/02 16:07:07 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(int fd, t_buf *buf)
{
	buf->size = read(fd, buf->buf, BUFFER_SIZE);
	buf->index = 0;
	return (buf->size);
}

int	append_line(char **line, int *line_index, char current_char)
{
	char	*new_line;

	new_line = ft_realloc(*line, (*line_index + 1) * sizeof(char));
	if (!new_line)
	{
		free (*line);
		return (-1);
	}
	*line = new_line;
	(*line)[(*line_index)++] = current_char;
	return (0);
}

void	finalize_line(char **line, int line_index)
{
	char	*new_line;

	new_line = ft_realloc(*line, (line_index + 1) * sizeof(char));
	if (!new_line)
	{
		free (*line);
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
	static t_buf	buf = {.index = 0, .size = 0};
	char			*line;
	int				line_index;
	char			current_char;

	line = NULL;
	line_index = 0;
	while (1)
	{
		if (buf.index >= buf.size)
		{
			if (read_buffer(fd, &buf) <= 0)
				break ;
		}
		current_char = buf.buf[buf.index++];
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
