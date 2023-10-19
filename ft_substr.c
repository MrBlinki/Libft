/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:27:10 by maroth            #+#    #+#             */
/*   Updated: 2023/10/19 19:49:33 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = (void *)0;
	substr = ft_calloc(len, sizeof(char));
	if (!substr)
		return ((void *)0);
	if (start > ft_strlen(s))
		return ((void *)0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
