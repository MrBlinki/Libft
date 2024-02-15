/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:55:34 by maroth            #+#    #+#             */
/*   Updated: 2024/02/15 11:51:35 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the string ’s’ to the given file descriptor.
// Returns number of bytes written, or -1 if write() throws an error
ssize_t	ft_putstr_fd(char *s, int fd)
{
	ssize_t	byte_count;
	ssize_t	temp_count;

	byte_count = 0;
	while (s && *s)
	{
		temp_count = ft_putchar_fd(*s, fd);
		if (temp_count < 0)
			return (-1);
		byte_count += temp_count;
		s++;
	}
	return (byte_count);
}
