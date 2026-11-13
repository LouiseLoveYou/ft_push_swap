/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 10:03:15 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:20:34 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Locates the last occurrence of a character in a string.
* @param s The string to search.
* @param c The character to search for.
* @return A pointer to the last occurrence of the character in the string,
* or NULL if not found.
*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = (0);
	while (*s)
	{
		if (*s == (char) c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return ((char *) last);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strrchr("hello", 'l'));
	return (0);
}
*/
