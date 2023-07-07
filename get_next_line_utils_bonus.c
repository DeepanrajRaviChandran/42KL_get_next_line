/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:57 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/07 13:06:12 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*Reallocate memory*/
void	*ft_realloc(void *ptr, size_t size)
{
	char	*dest;
	char	*src;
	int		i;

	dest = (char *)malloc(size + 1);
	if (!size)
	{
		free (ptr);
		return (NULL);
	}
	if (ptr)
	{
		src = (char *)ptr;
		i = -1;
		while ((size_t)(++i) < size)
			dest[i] = src[i];
		free(ptr);
	}
	return ((void *)dest);
}
