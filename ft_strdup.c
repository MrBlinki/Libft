/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:33:19 by maroth            #+#    #+#             */
/*   Updated: 2023/10/18 15:12:24 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	ptr = (void *)0;
	len = ft_strlen(s1);
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return ((void *)0);
	ft_memmove(ptr, s1, len);
	return (ptr);
}
