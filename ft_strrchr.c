/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:49:46 by maroth            #+#    #+#             */
/*   Updated: 2023/10/25 14:23:43 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a pointer to last occurence of c in s, NULL if not found
char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (void *)0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (ptr);
}
