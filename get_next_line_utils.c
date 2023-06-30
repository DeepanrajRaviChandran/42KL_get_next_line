/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:12:13 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/06/28 12:37:33 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Create New node which dynamically allocates memory for the line*/
t_list	*ft_lst_new_node(char *line)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->line = line;
	new_node->next = NULL;
	return (new_node);
}

/*Appends a node to the end of the list and initializes new last node*/
void	ft_lst_append_node(t_list **start, t_list **last, t_list *node)
{
	if (!*start)
		*start = node;
	else
		(*last)->next = node;
	*last = node;
}

/*Free Memory for all node*/
void	ft_free_node_mem(t_list *start)
{
	t_list	*temp;
	t_list	*next;

	temp = start;
	while (temp)
	{
		next = temp->next;
		free (temp->line);
		free (temp);
		temp = next;
	}
}

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
