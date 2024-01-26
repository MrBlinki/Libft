/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:06:34 by maroth            #+#    #+#             */
/*   Updated: 2024/01/12 12:10:04 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Returns the last node of a linked list
t_stash	*get_last_node(t_stash *stash)
{
	while (stash->next)
		stash = stash->next;
	return (stash);
}

// Returns 0 if a '\n' is found in buf or end of file is reached, 1 otherwise
int	check_buffer(char *buf)
{
	int	i;

	i = 0;
	while (*buf)
	{
		if (*buf == '\n')
			return (0);
		buf++;
		i++;
	}
	if (i < BUFFER_SIZE && i > 0)
		return (0);
	return (1);
}

// Malloc a new node and adds it at the end of the list
// Returns 0 on success, 1 if error
int	add_node(t_stash **stash)
{
	t_stash	*new_node;

	new_node = malloc(sizeof(t_stash));
	if (!new_node)
		return (1);
	set_buffer_zero(new_node->content, BUFFER_SIZE);
	new_node->next = (void *)0;
	if (!(*stash))
		*stash = new_node;
	else
		get_last_node(*stash)->next = new_node;
	return (0);
}

// Returns the length of the first line found in stash
int	get_line_len(t_stash *stash)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!stash)
		return (len);
	while (stash->content[i] != '\n')
	{
		if (!(stash->content[i]))
		{
			stash = stash->next;
			if (!stash)
				return (len);
			i = 0;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (++len);
}

// Sets n bytes to 0
void	set_buffer_zero(char *buf, int n)
{
	int	i;

	i = 0;
	while (i <= n)
		buf[i++] = '\0';
}
