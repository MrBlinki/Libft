/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:42:45 by maroth            #+#    #+#             */
/*   Updated: 2023/10/26 15:24:44 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		*copy_word(char const *s, char c);
static void		free_2d(char **array, size_t i);
static size_t	get_word_len(char const *s, char c);

// Allocates (with malloc(3)) and returns an array of strings obtained by
// splitting ’s’ using the character ’c’ as a delimiter. The array must end
// with a NULL pointer.
char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**splitted;

	if (!s)
		return ((void *)0);
	i = 0;
	splitted = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!splitted)
		return ((void *)0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			splitted[i] = copy_word(s, c);
			if (!splitted[i])
			{
				free_2d(splitted, i);
				return ((void *)0);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	return (splitted);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words_count;

	words_count = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c && *(s - 1) != c)
			words_count++;
		s++;
		if (!(*s) && *(s - 1) != c)
			words_count++;
	}
	return (words_count);
}

static char	*copy_word(char const *s, char c)
{
	size_t	i;
	size_t	word_len;
	char	*word;

	i = 0;
	word_len = get_word_len(s, c);
	word = ft_calloc(word_len + 1, sizeof(char));
	if (!word)
		return ((void *)0);
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static void	free_2d(char **array, size_t i)
{
	size_t	j;

	j= 0;
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*s && *s != c)
	{
		word_len++;
		s++;
	}
	return (word_len);
}
