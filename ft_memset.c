/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:50:22 by maroth            #+#    #+#             */
/*   Updated: 2023/10/15 16:12:31 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	

// Fills b with c for len bytes
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = (unsigned char) c;
	return (b);
}
