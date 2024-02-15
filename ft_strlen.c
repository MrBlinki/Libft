/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:09:51 by maroth            #+#    #+#             */
/*   Updated: 2024/02/14 16:10:44 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Returns length of the string s
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}
