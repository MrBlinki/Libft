/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:25:34 by maroth            #+#    #+#             */
/*   Updated: 2023/10/18 14:34:42 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates count * size bytes and fills area with 0
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)0;
	ptr = malloc(count * size);
	if (!ptr)
		return ((void *)0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
