/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 09:54:51 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:58:29 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Locates the first occurrence of a character in a string.
* @param s The string to search.
* @param c The character to search for.
* @return A pointer to the first occurrence of the character in the string,
* or NULL if not found.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strchr("hello", 'l'));
	return (0);
}
*/
