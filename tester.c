/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:12:28 by maroth            #+#    #+#             */
/*   Updated: 2023/10/13 18:50:00 by maroth           ###   ########.fr       */
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
	printf("\n========== FT_ISDIGIT ==========\n");
	printf("isdigit('0'):		%d\n", isdigit('0'));
	printf("ft_isdigit('0'):	%d\n", ft_isdigit('0'));
	printf("isdigit('a'):		%d\n", isdigit('a'));
	printf("ft_isdigit('a'):	%d\n", ft_isdigit('a'));
	printf("isdigit('9'):		%d\n", isdigit('9'));
	printf("ft_isdigit('9'):	%d\n", ft_isdigit('9'));
	printf("\n========== FT_ISALNUM ==========\n");
	printf("isalnum('0'):		%d\n", isalnum('0'));
	printf("ft_isalnum('0'):	%d\n", ft_isalnum('0'));
	printf("isalnum('~'):		%d\n", isalnum('~'));
	printf("ft_isalnum('~'):	%d\n", ft_isalnum('~'));
	printf("isalnum('a'):		%d\n", isalnum('a'));
	printf("ft_isalnum('a'):	%d\n", ft_isalnum('a'));
	printf("isalnum(' '):		%d\n", isalnum(' '));
	printf("ft_isalnum(' '):	%d\n", ft_isalnum(' '));
	printf("\n========== FT_ISASCII ==========\n");
	printf("isascii(0):		%d\n", isascii(0));
	printf("ft_isascii(0):		%d\n", ft_isascii(0));
	printf("isascii(-1):		%d\n", isascii(-1));
	printf("ft_isascii(-1):		%d\n", ft_isascii(-1));
	printf("isascii(127):		%d\n", isascii(127));
	printf("ft_isascii(127):	%d\n", ft_isascii(127));
	return (0);
}
