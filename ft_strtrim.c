/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:08:21 by maroth            #+#    #+#             */
/*   Updated: 2023/10/19 18:52:53 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*get_str_start(char const *s1, char const *set);
static char const	*get_str_end(char const *s1, char const *set);

// Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
// specified in ’set’ removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*str;
	size_t		trimmed_len;

	start = (void *)0;
	end = (void *)0;
	str = (void *)0;
	start = get_str_start(s1, set);
	end = get_str_end(s1, set);
	if (end >= start)
		trimmed_len = (end - start) + 2;
	else
		return ((void *)0);
	str = ft_calloc(trimmed_len, sizeof(char));
	if (!str)
		return ((void *)0);
	ft_strlcpy(str, start, trimmed_len);
	return (str);
}

static char const	*get_str_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == *s1)
		{
			s1++;
			i = 0;
		}
		else
			i++;
	}
	return (s1);
}

static char const	*get_str_end(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	s1 += ft_strlen(s1) - 1;
	while (set[i])
	{
		if (set[i] == *s1)
		{
			s1--;
			i = 0;
		}
		else
			i++;
	}
	return (s1);
}
