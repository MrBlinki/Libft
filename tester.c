/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:12:28 by maroth            #+#    #+#             */
/*   Updated: 2023/10/13 11:41:56 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <ctype.h>

int	main(void)
{
	printf("\n========== FT_ISALPHA ==========\n");
	printf("isalpha(4): 		%d\n", isalpha(4));
	printf("ft_isalpha(4): 		%d\n", ft_isalpha(4));
	printf("isalpha('a'): 		%d\n", isalpha('a'));
	printf("ft_isalpha('a'): 	%d\n", ft_isalpha('a'));
	printf("isalpha('Z'): 		%d\n", isalpha('Z'));
	printf("ft_isalpha('Z'): 	%d\n", ft_isalpha('Z'));
	printf("isalpha('A'): 		%d\n", isalpha('A'));
	printf("ft_isalpha('A'): 	%d\n", ft_isalpha('A'));
	return (0);
}
