/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:57 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/07/04 10:25:50 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Reallocate memory*/
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	char	*dest;
	char	*src;
	size_t	i;

	new_ptr = (char *)malloc(size + 1);
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
