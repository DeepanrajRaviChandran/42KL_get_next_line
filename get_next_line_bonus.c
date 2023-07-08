/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:12:13 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/08 19:41:23 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*reads from the file descriptor and appends the read content to the static
buffer until a newline character is encountered or
the end of the file is reached.*/
int	ft_read_fd(int fd, char **line_buffer, char *buffer)
{
	int	bytes;

	bytes = 1;
	while (!ft_strchr(*line_buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		buffer[bytes] = '\0';
		*line_buffer = ft_strjoin_mod(*line_buffer, buffer);
	}
	return (bytes);
}

/*Extracts the current line from a string until a
newline character or the end of the string.*/
char	*ft_get_line(char *str)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_line = malloc(i + 2);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, str, i + 2);
	return (new_line);
}

/*Cleans the static buffer by removing the current line
and returns the remaining contents.*/
char	*ft_strclean(char *line_buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!line_buffer)
		return (NULL);
	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i])
	{
		free(line_buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(line_buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line_buffer[i])
		str[j++] = line_buffer[i++];
	str[j] = '\0';
	free (line_buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_buffer[MAX_FD];
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = ft_read_fd(fd, &line_buffer[fd], buffer);
	if (bytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_get_line(line_buffer[fd]);
	line_buffer[fd] = ft_strclean(line_buffer[fd]);
	free(buffer);
	return (line);
}
/*
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
	system("leaks a.out");
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
