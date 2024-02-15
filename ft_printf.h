/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:25:12 by maroth            #+#    #+#             */
/*   Updated: 2024/02/15 16:34:52 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

#include "libft.h"

int		ft_printf(const char *format, ...);
int		print_percent(void);
int		print_string(char *str);
int		print_char(char c);
int		print_int(int i);
int		print_unsigned(unsigned int u);
int		print_hex(unsigned long h, char to_lower);
int		print_ptr(void *ptr);

// Will be added to libft
char	*ft_utoa(unsigned int n);
char	*ft_utohex(unsigned long n);

#endif