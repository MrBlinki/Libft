/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:23:14 by maroth            #+#    #+#             */
/*   Updated: 2023/10/16 12:42:43 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies len bytes from src to dst in a non-destructive manner in case they
// overlap
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}
