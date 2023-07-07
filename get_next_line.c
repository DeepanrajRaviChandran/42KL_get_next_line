/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:12:13 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/08 00:07:45 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_and_return(void *var, void *ret)
{
	free(var);
	return (ret);
}

char	*get_current_line(char *str)
{
	int		i;
	char	*new_line;

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

char	*ft_strclean(char *static_buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!static_buffer)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i])
		str[j++] = static_buffer[i++];
	str[j] = '\0';
	return (free_and_return(static_buffer, str));
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*static_buffer;
	char		*buffer;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(static_buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_and_return(buffer, NULL));
		buffer[read_bytes] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	ret = get_current_line(static_buffer);
	static_buffer = ft_strclean(static_buffer);
	return (free_and_return(buffer, ret));
}
