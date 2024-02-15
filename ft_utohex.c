/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:37:57 by maroth            #+#    #+#             */
/*   Updated: 2024/02/15 16:28:04 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_symbols(unsigned long n);
static void		copy_num(char *dest, unsigned long n, size_t hexlen);

// Allocates (with malloc(3)) and returns a string representing the unsigned
// long long received as an argument, converted to hexadecimal
char	*ft_utohex(unsigned long n)
{
	char	*str;
	size_t	hexlen;

	str = (void *)0;
	hexlen = count_symbols((long)n);
	str = ft_calloc(hexlen + 2, sizeof(char));
	if (!str)
		return ((void *)0);
	copy_num(str, n, hexlen);
	return (str);
}

static size_t	count_symbols(unsigned long n)
{
	size_t	symbols_count;

	symbols_count = 0;
	while (n > 0)
	{
		n /= 16;
		symbols_count++;
	}
	return (symbols_count);
}

static void	copy_num(char *dest, unsigned long n, size_t hexlen)
{
	long	mod;

	if (n == 0)
		dest[0] = '0';
	while (n > 0)
	{
		mod = n % 16;
		if (mod < 10)
			dest[hexlen - 1] = mod + '0';
		else
			dest[hexlen - 1] = mod + 55;
		hexlen--;
		n /= 16;
	}
}
