/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:05:54 by maroth            #+#    #+#             */
/*   Updated: 2024/01/14 18:09:04 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Copies content of buf into stash_content
static void	copy_buf_to_stash(char *buf, char *stash_content)
{
	while (*buf)
	{
		*stash_content = *buf;
		stash_content++;
		buf++;
	}
}

// Copies line stored in stash to line
static void	copy_stash_to_line(char *line, t_stash *stash)
{
	int	i;

	i = 0;
	while (stash->content[i] != '\n')
	{
		if (!(stash->content[i]))
		{
			if (stash->next)
				stash = stash->next;
			else
				break ;
			i = 0;
		}
		else
		{
			*line = stash->content[i];
			line++;
			i++;
		}
	}
	if (stash->content[i] == '\n')
		*line = '\n';
	else
		*line = '\0';
}

// Mallocs and returns a pointer to the line
static char	*get_line(t_stash *stash, int read_res)
{
	char	*line;
	int		line_len;

	line = (void *)0;
	if (read_res < 0)
		return ((void *)0);
	line_len = get_line_len(stash);
	if (line_len > 0)
		line = malloc((line_len + 1) * sizeof(char));
	if (!line)
		return ((void *)0);
	set_buffer_zero(line, line_len);
	copy_stash_to_line(line, stash);
	return (line);
}

// Frees memory in the stash and returns new first node
static t_stash	*clean_stash(t_stash *stash)
{
	int		i;
	int		j;
	t_stash	*temp_node;

	i = 0;
	j = 0;
	temp_node = (void *)0;
	while (stash->content[i] != '\n' && stash->next)
	{
		if (!stash->content[i])
		{
			temp_node = stash;
			stash = stash->next;
			free(temp_node);
			i = 0;
		}
		else
			i++;
	}
	while (stash->content[i] != '\n' && stash->content[i])
		i++;
	while (++i < BUFFER_SIZE)
		stash->content[j++] = stash->content[i];
	set_buffer_zero(stash->content + j, i - j);
	return (stash);
}

// Returns a line read from the file descriptor fd
char	*get_next_line(int fd)
{
	static t_stash	*stash = (void *)0;
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	int				read_res;

	set_buffer_zero(buf, BUFFER_SIZE);
	while (check_buffer(buf))
	{
		set_buffer_zero(buf, BUFFER_SIZE);
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res < 1)
			break ;
		if (add_node(&stash))
			return ((void *)0);
		copy_buf_to_stash(buf, get_last_node(stash)->content);
	}
	line = get_line(stash, read_res);
	if (stash)
		stash = clean_stash(stash);
	if (!line)
	{
		free(stash);
		stash = (void *)0;
	}
	return (line);
}
