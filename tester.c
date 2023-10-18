/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:12:28 by maroth            #+#    #+#             */
/*   Updated: 2023/10/18 14:24:25 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

// BSD lib installed for ubuntu
#ifdef __linux__
# include <bsd/string.h>
#endif

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
	printf("\n========== FT_TOUPPER ==========\n");
	printf("toupper('a'): 		%c\n", toupper('a'));
	printf("ft_toupper('a'): 	%c\n", ft_toupper('a'));
	printf("toupper('4'): 		%c\n", toupper('4'));
	printf("ft_toupper('4'): 	%c\n", ft_toupper('4'));
	printf("toupper('Z'): 		%c\n", toupper('Z'));
	printf("ft_toupper('Z'): 	%c\n", ft_toupper('Z'));
	printf("toupper(4): 		%c\n", toupper(4));
	printf("ft_toupper(4): 	%c\n", ft_toupper(4));
	printf("\n========== FT_TOLOWER ==========\n");
	printf("tolower('a'): 		%c\n", tolower('a'));
	printf("ft_tolower('a'): 	%c\n", ft_tolower('a'));
	printf("tolower('4'): 		%c\n", tolower('4'));
	printf("ft_tolower('4'): 	%c\n", ft_tolower('4'));
	printf("tolower('Z'): 		%c\n", tolower('Z'));
	printf("ft_tolower('Z'): 	%c\n", ft_tolower('Z'));
	printf("tolower(4): 		%c\n", tolower(4));
	printf("ft_tolower(4): 	%c\n", ft_tolower(4));
	printf("\n========== FT_STRCHR ==========\n");
	char	str_tosearch[] = "abcdefghijklmnopqrstuvwxyz12345ddaa";
	printf("Looking for 'm' with strchr:		%p\n", strchr(str_tosearch, 'm'));
	printf("Looking for 'm' with ft_strchr:		%p\n", ft_strchr(str_tosearch, 'm'));
	printf("Looking for 'a' with strchr:		%p\n", strchr(str_tosearch, 'a'));
	printf("Looking for 'a' with ft_strchr:		%p\n", ft_strchr(str_tosearch, 'a'));
	printf("Looking for 'A' with strchr:		%p\n", strchr(str_tosearch, 'A'));
	printf("Looking for 'A' with ft_strchr:		%p\n", ft_strchr(str_tosearch, 'A'));
	printf("Looking for '\\0' with strchr:		%p\n", strchr(str_tosearch, '\0'));
	printf("Looking for '\\0' with ft_strchr:	%p\n", ft_strchr(str_tosearch, '\0'));
	printf("\n========== FT_STRRCHR ==========\n");
	printf("Looking for 'd' with strrchr:		%p\n", strrchr(str_tosearch, 'm'));
	printf("Looking for 'd' with ft_strrchr:	%p\n", ft_strrchr(str_tosearch, 'm'));
	printf("Looking for 'a' with strrchr:		%p\n", strrchr(str_tosearch, 'a'));
	printf("Looking for 'a' with ft_strrchr:	%p\n", ft_strrchr(str_tosearch, 'a'));
	printf("Looking for 'A' with strrchr:		%p\n", strrchr(str_tosearch, 'A'));
	printf("Looking for 'A' with ft_strrchr:	%p\n", ft_strrchr(str_tosearch, 'A'));
	printf("Looking for '\\0' with strrchr:		%p\n", strrchr(str_tosearch, '\0'));
	printf("Looking for '\\0' with ft_strrchr:	%p\n", ft_strrchr(str_tosearch, '\0'));
	printf("\n========== FT_STRNCMP ==========\n");
	printf("strncmp		(\"\", \"\", 3):	%d\n", strncmp("", "", 3));
	printf("ft_strncmp	(\"\", \"\", 3):	%d\n", ft_strncmp("", "", 3));
	printf("strncmp		(\"aaa\", \"aaa\", 3):	%d\n", strncmp("aaa", "aaa", 3));
	printf("ft_strncmp	(\"aaa\", \"aaa\", 3):	%d\n", ft_strncmp("aaa", "aaa", 3));
	printf("strncmp		(\"aaa\", \"aab\", 3):	%d\n", strncmp("aaa", "aab", 3));
	printf("ft_strncmp	(\"aaa\", \"aab\", 3):	%d\n", ft_strncmp("aaa", "aab", 3));
	printf("strncmp		(\"aaa\", \"aab\", 2):	%d\n", strncmp("aaa", "aab", 2));
	printf("ft_strncmp	(\"aaa\", \"aab\", 2):	%d\n", ft_strncmp("aaa", "aab", 2));
	printf("strncmp		(\"aaa\", \"42ab\", 5):	%d\n", strncmp("aaa", "42ab", 5));
	printf("ft_strncmp	(\"aaa\", \"42ab\", 5):	%d\n", ft_strncmp("aaa", "42ab", 5));
	printf("strncmp		(\"aaa\", \"aaaa\", 5):	%d\n", strncmp("aaa", "aaaa", 5));
	printf("ft_strncmp	(\"aaa\", \"aaaa\", 5):	%d\n", ft_strncmp("aaa", "aaaa", 5));
	printf("\n========== FT_MEMCHR ==========\n");
	printf("memchr 		searching 'a' on 0 bytes:	%p\n", memchr(str_tosearch, 'a', 0));
	printf("ft_memchr 	searching 'a' on 0 bytes:	%p\n", ft_memchr(str_tosearch, 'a', 0));
	printf("memchr 		searching 'a' on 1 byte:	%p\n", memchr(str_tosearch, 'a', 1));
	printf("ft_memchr 	searching 'a' on 1 byte:	%p\n", ft_memchr(str_tosearch, 'a', 1));
	printf("memchr 		searching 'm' on 10 bytes:	%p\n", memchr(str_tosearch, 'm', 10));
	printf("ft_memchr 	searching 'm' on 10 bytes:	%p\n", ft_memchr(str_tosearch, 'm', 10));
	printf("memchr 		searching 'm' on 50 bytes:	%p\n", memchr(str_tosearch, 'm', 50));
	printf("ft_memchr 	searching 'm' on 50 bytes:	%p\n", ft_memchr(str_tosearch, 'm', 50));
	printf("memchr 		searching '9' on 50 bytes:	%p\n", memchr(str_tosearch, '9', 50));
	printf("ft_memchr 	searching '9' on 50 bytes:	%p\n", ft_memchr(str_tosearch, '9', 50));
	printf("\n========== FT_MEMCMP ==========\n");
	printf("memcmp		(\"\", \"\", 3):		%d\n", memcmp("", "", 3));
	printf("ft_memcmp	(\"\", \"\", 3):		%d\n", ft_memcmp("", "", 3));
	printf("memcmp		(\"aaa\", \"aaa\", 3):	%d\n", memcmp("aaa", "aaa", 3));
	printf("ft_memcmp	(\"aaa\", \"aaa\", 3):	%d\n", ft_memcmp("aaa", "aaa", 3));
	printf("memcmp		(\"aaa\", \"aab\", 3):	%d\n", memcmp("aaa", "aab", 3));
	printf("ft_memcmp	(\"aaa\", \"aab\", 3):	%d\n", ft_memcmp("aaa", "aab", 3));
	printf("memcmp		(\"aaa\", \"aab\", 2):	%d\n", memcmp("aaa", "aab", 2));
	printf("ft_memcmp	(\"aaa\", \"aab\", 2):	%d\n", ft_memcmp("aaa", "aab", 2));
	printf("memcmp		(\"aaa\", \"42ab\", 5):	%d\n", memcmp("aaa", "42ab", 5));
	printf("ft_memcmp	(\"aaa\", \"42ab\", 5):	%d\n", ft_memcmp("aaa", "42ab", 5));
	printf("memcmp		(\"aaa\", \"aaaa\", 5):	%d\n", memcmp("aaa", "aaaa", 5));
	printf("ft_memcmp	(\"aaa\", \"aaaa\", 5):	%d\n", ft_memcmp("aaa", "aaaa", 5));
	printf("\n========== FT_STRNSTR ==========\n");
	char	haystack[] = "adyqehdsHelloHelloWorldtest1234";
	printf("strnstr 	looking for \"\" on 32 bytes:	%pn\n", strnstr(haystack, "", 32));
	printf("ft_strnstr 	looking for \"\" on 32 bytes:	%pn\n", ft_strnstr(haystack, "", 32));
	printf("strnstr 	looking for \"test\" on 32 bytes:	%pn\n", strnstr(haystack, "test", 32));
	printf("ft_strnstr 	looking for \"test\" on 32 bytes:	%pn\n", ft_strnstr(haystack, "test", 32));
	printf("strnstr 	looking for \"test\" on 27 bytes:	%pn\n", strnstr(haystack, "test", 27));
	printf("ft_strnstr 	looking for \"test\" on 27 bytes:	%pn\n", ft_strnstr(haystack, "test", 27));
	printf("strnstr 	looking for \"test\" on 26 bytes:	%pn\n", strnstr(haystack, "test", 26));
	printf("ft_strnstr 	looking for \"test\" on 26 bytes:	%pn\n", ft_strnstr(haystack, "test", 26));
	printf("strnstr 	looking for \"Hello\" on 32 bytes:	%pn\n", strnstr(haystack, "Hello", 32));
	printf("ft_strnstr 	looking for \"Hello\" on 32 bytes:	%pn\n", ft_strnstr(haystack, "Hello", 32));
	printf("strnstr 	looking for \"HelloWorld\" on 32 bytes:	%pn\n", strnstr(haystack, "HelloWorld", 32));
	printf("ft_strnstr 	looking for \"HelloWorld\" on 32 bytes:	%pn\n", ft_strnstr(haystack, "HelloWorld", 32));
	printf("\n========== FT_ATOI ==========\n");
	printf("atoi(\"\"):		%d\n", atoi(""));
	printf("ft_atoi(\"\"):		%d\n", ft_atoi(""));
	printf("atoi(\"abcd\"):		%d\n", atoi("abcd"));
	printf("ft_atoi(\"abcd\"):	%d\n", ft_atoi("abcd"));
	printf("atoi(\"42\"):		%d\n", atoi("42"));
	printf("ft_atoi(\"42\"):		%d\n", ft_atoi("42"));
	printf("atoi(\"42abc\"):		%d\n", atoi("42abc"));
	printf("ft_atoi(\"42abc\"):	%d\n", ft_atoi("42abc"));
	printf("atoi(\"abc123abc\"):	%d\n", atoi("abc123abc"));
	printf("ft_atoi(\"abc123abc\"):	%d\n", ft_atoi("abc123abc"));
	printf("atoi(\"   123\"):		%d\n", atoi("   123"));
	printf("ft_atoi(\"   123\"):	%d\n", ft_atoi("   123"));
	printf("atoi(\"+256\"):		%d\n", atoi("+256"));
	printf("ft_atoi(\"+256\"):	%d\n", ft_atoi("+256"));
	printf("atoi(\" ++256\"):		%d\n", atoi(" ++256"));
	printf("ft_atoi(\" ++256\"):	%d\n", ft_atoi(" ++256"));
	printf("atoi(\"-256\"):		%d\n", atoi("-256"));
	printf("ft_atoi(\"-256\"):	%d\n", ft_atoi("-256"));
	printf("atoi(\"--256\"):		%d\n", atoi("--256"));
	printf("ft_atoi(\"--256\"):	%d\n", ft_atoi("--256"));
	printf("atoi(\"-  256\"):		%d\n", atoi("-  256"));
	printf("ft_atoi(\"-  256\"):	%d\n", ft_atoi("-  256"));
	printf("atoi(\"-+256\"):		%d\n", atoi("-+256"));
	printf("ft_atoi(\"-+256\"):	%d\n", ft_atoi("-+256"));
	printf("atoi(\"+-256\"):		%d\n", atoi("+-256"));
	printf("ft_atoi(\"+-256\"):	%d\n", ft_atoi("+-256"));
	printf("\n========== FT_CALLOC ==========\n");
	void	*ptr;
	ptr = (void *)0;
	ptr = ft_calloc(5, sizeof(char));
	printf("Allocating with ft_calloc: %p\n", ptr);
	free(ptr);
	return (0);
}
