/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:06:13 by maroth            #+#    #+#             */
/*   Updated: 2024/01/12 12:08:48 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_stash {
	char			content[BUFFER_SIZE + 1];
	struct s_stash	*next;
}	t_stash;

char	*get_next_line(int fd);
t_stash	*get_last_node(t_stash *stash);
int		check_buffer(char *buf);
int		add_node(t_stash **stash);
int		get_line_len(t_stash *stash);
void	set_buffer_zero(char *buf, int n);

#endif