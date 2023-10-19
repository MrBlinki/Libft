/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:33:19 by maroth            #+#    #+#             */
/*   Updated: 2023/10/19 13:06:50 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to copy of s1 in allocated memory
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	ptr = (void *)0;
	len = ft_strlen(s1) + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return ((void *)0);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}
