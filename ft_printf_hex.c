/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:49:09 by maroth            #+#    #+#             */
/*   Updated: 2024/02/15 12:10:16 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long h, char to_lower)
{
	int		i;
	char	*hex;
	int		hex_len;

	i = 0;
	hex = ft_utohex(h);
	if (!hex)
		return (-1);
	if (to_lower)
	{
		while (hex[i])
		{
			hex[i] = ft_tolower(hex[i]);
			i++;
		}
	}
	if (ft_putstr_fd(hex, 1) < 0)
	{
		free(hex);
		return (-1);
	}
	hex_len = ft_strlen(hex);
	free(hex);
	return (hex_len);
}

int	print_ptr(void *ptr)
{
	unsigned long		ul_ptr;
	int					ptr_len;

	ul_ptr = (unsigned long) ptr;
	if (ft_putstr_fd("0x", 1) < 0)
		return (-1);
	ptr_len = print_hex(ul_ptr, 1);
	if (ptr_len < 0)
		return (-1);
	return (ptr_len + 2);
}
