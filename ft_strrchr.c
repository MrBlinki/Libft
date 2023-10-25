/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:49:46 by maroth            #+#    #+#             */
/*   Updated: 2023/10/25 14:38:02 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a pointer to last occurence of c in s, NULL if not found
char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	c = (unsigned char)c;
	ptr = (void *)0;
	while (*s)
	{
		if (*s == c)
			ptr = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (ptr);
}
