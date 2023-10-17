/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:12:28 by maroth            #+#    #+#             */
/*   Updated: 2023/10/17 09:25:29 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <ctype.h>
#include <string.h>
#include <unistd.h>

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
	printf("\n========== FT_ISPRINT ==========\n");
	printf("isprint(' '):		%d\n", isprint(' '));
	printf("ft_isprint(' '):	%d\n", ft_isprint(' '));
	printf("isprint(127):		%d\n", isprint(127));
	printf("ft_isprint(127):	%d\n", ft_isprint(127));
	printf("isprint('~'):		%d\n", isprint('~'));
	printf("ft_isprint('~'):	%d\n", ft_isprint('~'));
	printf("isprint(31):		%d\n", isprint(31));
	printf("ft_isprint(31):		%d\n", ft_isprint(31));
	printf("\n========== FT_STRLEN ==========\n");
	printf("strlen(\"Hello World\")		%ld\n", strlen("Hello World"));
	printf("ft_strlen(\"Hello World\"):	%ld\n", ft_strlen("Hello World"));
	printf("strlen(\"\")			%ld\n", strlen(""));
	printf("ft_strlen(\"\"):			%ld\n", ft_strlen(""));
	printf("strlen(\"	\")		%ld\n", strlen("	"));
	printf("ft_strlen(\"	\"):		%ld\n", ft_strlen("	"));
	printf("strlen(\"  test  \\n\")		%ld\n", strlen("  test  \n"));
	printf("ft_strlen(\"  test  \\n\"):	%ld\n", ft_strlen("  test  \n"));
	printf("\n========== FT_MEMSET ==========\n");
	char	b[20];
	write(1, "Setting 20 bytes to 'a': ", 25);
	write(1, ft_memset(b, 'a', 20), 20);
	write(1, "\n", 1);
	write(1, "Setting 10 bytes to 'b': ", 25);
	write(1, ft_memset(b, 'b', 10), 20);
	write(1, "\n", 1);
	printf("\n========== FT_BZERO ==========\n");
	write(1, "ft_bzero on 16 bytes: ", 22);
	ft_bzero(b, 16);
	write(1, b, 20);
	write(1, "\n", 1);
	printf("\n========== FT_MEMCPY ==========\n");
	char	src[6] = "Hello";
	char	dst[6];
	write(1, "ft_memcpy 6 bytes from src, dst: ", 33);
	write(1, ft_memcpy(dst, src, 6), 6);
	write(1, "\n", 1);
	printf("\n========== FT_MEMMOVE ==========\n");
	char	src2[12] = "Hello World";
	write(1, "ft_memmove(src+2, src, 5):", 26);
	write(1, ft_memmove(src2+2, src2, 5), 20);
	write(1, "\n", 1);
	printf("\n========== FT_STRLCPY ==========\n");
	char	str[] = "abcd";
	char	str2[4];
	printf("Value returned by strlcpy:	%ld\n", strlcpy(str2, str, 4));
	printf("Copied string:			%s\n", str2);
	printf("Value returned by ft_strlcpy: 	%ld\n", ft_strlcpy(str2, str, 4));
	printf("Copied string:			%s\n", str2);
	printf("\n========== FT_STRLCAT ==========\n");
	char	stra[20] = "Hello";
	char	strb[] = "World";
	char	strc[20] = "Hello";
	char	strd[] = "World";
	printf("Value returned by strlcat:	%ld\n", strlcat(stra, strb, 11));
	printf("Concatenated string:		%s\n", stra);
	printf("Value returned by ft_strlcat:	%ld\n", ft_strlcat(strc, strd, 11));
	printf("Concatenated string:		%s\n", strc);
	return (0);
}
