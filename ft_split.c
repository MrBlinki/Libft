/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroth <maroth@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:29:04 by maroth            #+#    #+#             */
/*   Updated: 2023/10/21 21:06:58 by maroth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_count(char const *s, char c);
static size_t	get_word_len(char const *s, char c);
static void		free_2d(char **arr, size_t size);
static void		fill_word(char *ptr, char const *s, char c);

// Allocates (with malloc(3)) and returns an array of strings obtained by
// splitting ’s’ using the character ’c’ as a delimiter. The array must end
// with a NULL pointer

#include <stdio.h>		//TOREMOVE

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_len;
	size_t	word_count;
	char	**splitted;

	i = 0;
	word_len = 0;
	word_count = get_word_count(s, c);
	printf("Word count: %ld\n", word_count);	//TOREMOVE
	splitted = (void *)0;
	if (ft_strlen(s) == 0)
		return ((void *)0);
	splitted = ft_calloc(word_count + 1, sizeof(char *));
	if (!splitted)
		return ((void *)0);
	while (i < word_count)
	{
		word_len = get_word_len(s + word_len, c);
		printf("Word length: %ld\n", word_len);	//TOREMOVE
		splitted[i] = ft_calloc(word_len, sizeof(char));
		printf("Word address: %p\n", splitted[i]);	//TOREMOVE
		if (!splitted[i])
		{
			free_2d(splitted, i + 1);
			return ((void *)0);
		}
		fill_word(splitted[i], s + word_len, c);
		i++;
	}
	return (splitted);
}

static size_t	get_word_count(char const *s, char c)
{
	size_t	word_count;

	word_count = 1;
	while (*s)
	{
		if (*s == c)
			word_count++;
		s++;
	}
	return (word_count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	printf("First letter of word: %c\n", *s);
	while (*s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	free_2d(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

static void	fill_word(char *ptr, char const *s, char c)
{
	while (*s != c)
	{
		*ptr = *s;
		ptr++;
		s++;
	}
}
