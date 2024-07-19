/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:19:56 by maroth            #+#    #+#             */
/*   Updated: 2024/07/19 10:15:03 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_res(long res, const char *str_head, int sign)
{
	if (!ft_isdigit(*str_head))
		return (1);
	if ((res < 0 && sign < 0) || (res >= 0 && sign > 0))
	{
		while (res != 0 && *str_head)
		{
			res /= 10;
			str_head++;
		}
		if (res == 0 && !(*str_head))
			return (0);
		return (1);
	}
	return (1);
}

// Returns str as a long (0 if conversion impossible)
long	ft_atol(const char *str)
{
	long		res;
	int			sign;
	const char	*str_head;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
			str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	str_head = str;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	if (check_res(res, str_head, sign))
		return (0);
	return (res);
}
