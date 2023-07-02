/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:57 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/02 16:22:52 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*Reallocate memory*/
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	char	*dest;
	char	*src;
	size_t	i;

	new_ptr = malloc(size);
	if (!size || !new_ptr)
	{
		free (ptr);
		return (NULL);
	}
	if (ptr)
	{
		src = (char *)ptr;
		dest = (char *)new_ptr;
		i = 0;
		while (i < size)
		{
			dest[i] = src[i];
			i++;
		}
		free(ptr);
	}
	return (new_ptr);
}
