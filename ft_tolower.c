/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:05:26 by maroth            #+#    #+#             */
/*   Updated: 2023/10/17 10:06:38 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns c lowercased if it was a upper-case character
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
