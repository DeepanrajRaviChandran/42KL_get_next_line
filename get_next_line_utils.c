/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:57 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/08 18:53:25 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Calculates the length of a string*/
size_t	ft_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*Concatenates two strings and returns the the combined string*/
char	*ft_strjoin_mod(char *s1, char *s2)
{
	int		i;
	int		lens1;
	int		lens2;
	int		size;
	char	*fin_str;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	size = lens1 + lens2;
	fin_str = (char *)malloc(sizeof(char) * (size + 1));
	if (!fin_str)
	{
		free (fin_str);
		return (NULL);
	}
	i = -1;
	while (++i < lens1)
		fin_str[i] = s1[i];
	i = -1;
	while (++i < lens2)
		fin_str[i + lens1] = s2[i];
	fin_str[size] = '\0';
	free (s1);
	return (fin_str);
}

/*Searches for the first occurrence of a character in a string*/
char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*Safely copies a src to a destination and returns length*/
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	results;

	results = 0;
	while (src[results])
		results++;
	if (size < 1)
		return (results);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (results);
}
