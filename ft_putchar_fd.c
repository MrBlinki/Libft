/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:49:23 by maroth            #+#    #+#             */
/*   Updated: 2024/02/15 11:35:04 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Outputs the character ’c’ to the given file descriptor.
// Returns the write() result -> Bytes written or -1 if error
ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
