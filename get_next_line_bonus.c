/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:12:13 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/04 08:39:13 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static t_buf	buf[MAX_FD] = {{0}};
	char			*line;
	int				line_index;
	char			current_char;

	line = NULL;
	line_index = 0;
	while (1)
	{
		if (buf[fd].index >= buf[fd].size)
		{
			if (read_buffer(fd, &buf[fd]) <= 0)
				break ;
		}
		current_char = buf[fd].buf[buf[fd].index++];
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
/*
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("File 1: %s\n", line);
		free(line);
	}

	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("File 2: %s\n", line);
		free(line);
	}

	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("File 3: %s\n", line);
		free(line);
	}

	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}
*/
