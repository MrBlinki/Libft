/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:22:34 by maroth            #+#    #+#             */
/*   Updated: 2024/02/15 11:36:56 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_specifier(char specifier, va_list args)
{
	int	printed_count;

	(void)args;
	printed_count = 0;
	if (specifier == '%')
		printed_count = print_percent();
	if (specifier == 's')
		printed_count = print_string(va_arg(args, char *));
	if (specifier == 'c')
		printed_count = print_char(va_arg(args, int));
	if (specifier == 'i' || specifier == 'd')
		printed_count = print_int(va_arg(args, int));
	if (specifier == 'u')
		printed_count = print_unsigned(va_arg(args, unsigned int));
	if (specifier == 'X')
		printed_count = print_hex(va_arg(args, unsigned int), 0);
	if (specifier == 'x')
		printed_count = print_hex(va_arg(args, unsigned int), 1);
	if (specifier == 'p')
		printed_count = print_ptr(va_arg(args, void *));
	return (printed_count);
}

int	ft_printf(const char *format, ...)
{
	int		char_count;
	int		temp_count;
	va_list	args;

	char_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			temp_count = check_specifier(*++format, args);
			if (temp_count < 0)
				return (-1);
			format++;
			char_count += temp_count - 1;
		}
		else
		{
			if (ft_putchar_fd(*format++, 1) < 0)
				return (-1);
		}
		char_count++;
	}
	va_end(args);
	return (char_count);
}
