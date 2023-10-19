/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:39:04 by maroth            #+#    #+#             */
/*   Updated: 2023/10/19 14:54:08 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	strlen;

	str = (void *)0;
	strlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(strlen, sizeof(char));
	if (!str)
		return ((void *)0);
	ft_strlcat(str, s1, strlen);
	ft_strlcat(str, s2, strlen);
	return (str);
}
