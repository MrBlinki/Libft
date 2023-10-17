/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:13 by maroth            #+#    #+#             */
/*   Updated: 2023/10/17 18:33:28 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack && i++ < len)
	{
		// If needle found, return pointer to the first character of the first occurence
		if (*haystack == *needle)
		{
			if(ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return ((void *)0);	// If needle not found, return NULL -> (void *)0
}
