/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:13 by maroth            #+#    #+#             */
/*   Updated: 2023/10/18 11:29:00 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Looks for needle in haystack within len bytes, returns a pointer if found
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		if (*haystack == *needle)
		{
			if (i + needle_len <= len)
				if (ft_strncmp(haystack, needle, needle_len) == 0)
					return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return ((void *)0);
}
