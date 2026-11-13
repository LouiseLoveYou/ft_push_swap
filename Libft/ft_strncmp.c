/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strncmp.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 10:17:27 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 13:48:48 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Compares two strings up to a specified number of characters.
* @param s1 The first string to compare.
* @param s2 The second string to compare.
* @param n The maximum number of characters to compare.
* @return An integer less than, equal to, or greater than zero if s1 is found,
* respectively, to be less than, to match, or be greater than s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("abc", "abd", 3));
	return (0);
}
*/
