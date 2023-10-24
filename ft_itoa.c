/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:37:57 by maroth            #+#    #+#             */
/*   Updated: 2023/10/24 14:40:41 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long n);
static void		copy_num(char *dest, long n, size_t numlen);

// Allocates (with malloc(3)) and returns a string representing the integer
// received as an argument. Negative numbers must be handled.
char	*ft_itoa(int n)
{
	char	*str;
	size_t	numlen;

	str = (void *)0;
	numlen = count_digits((long)n);
	if (n <= 0)
		numlen++;
	str = ft_calloc(numlen + 1, sizeof(char));
	if (!str)
		return ((void *)0);
	copy_num(str, (long)n, numlen);
	return (str);
}

static size_t	count_digits(long n)
{
	size_t	digits_count;

	digits_count = 0;
	if (n < 0)
		n = -n;
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
	if (n < 0)
	{
		dest[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		dest[numlen - 1] = (n % 10) + '0';
		numlen--;
		n /= 10;
	}
}
