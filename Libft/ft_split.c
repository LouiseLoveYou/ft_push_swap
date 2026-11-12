/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 13:18:21 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 13:48:25 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Counts the number of words in a string separated by a delimiter.
* @param s The string to count words in.
* @param c The delimiter character used to separate words.
* @return The number of words in the string.
*/

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

/**
* @brief Frees the memory allocated for the split array.
* @param result The array to free.
* @param count The number of elements in the array.
*/

static void	ft_free_split(char **result, size_t count)
{
	while (count > 0)
	{
		count--;
		free(result[count]);
	}
	free(result);
}

/**
* @brief Fills the result array with substrings from the input string.
* @param result The array to fill with substrings.
* @param s The input string to split.
* @param c The delimiter character used to split the string.
* @return 1 on success, 0 on failure (memory allocation error).
*/

static int	ft_fill_split(char **result, char const *s, char c)
{
	char	*word;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			word = ft_substr(s, start, i - start);
			if (!word)
				return (ft_free_split(result, j), 0);
			result[j++] = word;
		}
	}
	result[j] = NULL;
	return (1);
}

/**
* @brief Splits a string into an array of strings based on a delimiter.
* @param s The string to be split.
* @param c The delimiter character used to split the string.
* @return A pointer to the array of strings, or NULL if memory allocation fails.
*/

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_fill_split(result, s, c))
		return (NULL);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**tab;
	int		i;

	tab = ft_split("hello world 42", ' ');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/
