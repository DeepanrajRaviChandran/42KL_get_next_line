/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:06:45 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/08 18:33:19 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*Utility Funtion*/
size_t	ft_strlen(char *s);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);

/*Main Funtions*/
int		ft_read_fd(int fd, char **line_buffer, char *buffer);
char	*ft_get_line(char *s);
char	*ft_strclean(char *line_buffer);
char	*get_next_line(int fd);

#endif
