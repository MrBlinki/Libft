/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:37:13 by maroth            #+#    #+#             */
/*   Updated: 2023/10/25 13:51:32 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Appends src after dst, NUL-terminating src
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	j;

	dstlen = ft_strlen(dst);
	i = ft_strlen(dst);
	j = 0;
	while (i + 1 < dstsize && src[j])
		dst[i++] = src[j++];
	if (dstsize > 0)
		dst[i] = '\0';
	if (dstsize >= dstlen)
		return (dstlen + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}
