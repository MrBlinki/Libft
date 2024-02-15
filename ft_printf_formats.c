/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:20:14 by maroth            #+#    #+#             */
/*   Updated: 2024/02/15 12:56:58 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(void)
{
	return (ft_putchar_fd('%', 1));
}

int	print_string(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

int	print_char(char c)
{
	return (ft_putchar_fd(c, 1));
}

int	print_int(int i)
{
	char	*num;
	int		num_len;

	num = ft_itoa(i);
	if (!num)
		return (-1);
	if (ft_putstr_fd(num, 1) < 0)
	{
		free(num);
		return (-1);
	}
	num_len = ft_strlen(num);
	free(num);
	return (num_len);
}

int	print_unsigned(unsigned int u)
{
	char	*num;
	int		num_len;

	num = ft_utoa(u);
	if (!num)
		return (-1);
	if (ft_putstr_fd(num, 1) < 0)
	{
		free (num);
		return (-1);
	}
	num_len = ft_strlen(num);
	free(num);
	return (num_len);
}
