/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:37:57 by maroth            #+#    #+#             */
/*   Updated: 2024/02/15 16:27:55 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long n);
static void		copy_num(char *dest, long n, size_t numlen);

// Allocates (with malloc(3)) and returns a string representing the unsigned
// integer received as an argument.
char	*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	numlen;

	str = (void *)0;
	numlen = count_digits((long)n);
	str = ft_calloc(numlen + 2, sizeof(char));
	if (!str)
		return ((void *)0);
	copy_num(str, (long)n, numlen);
	return (str);
}

static size_t	count_digits(long n)
{
	size_t	digits_count;

	digits_count = 0;
	while (n > 0)
	{
		n /= 10;
		digits_count++;
	}
	return (digits_count);
}

static void	copy_num(char *dest, long n, size_t numlen)
{
	if (n == 0)
		dest[0] = '0';
	while (n > 0)
	{
		dest[numlen - 1] = (n % 10) + '0';
		numlen--;
		n /= 10;
	}
}
