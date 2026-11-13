/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 10:28:37 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:29:05 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Searches for the first occurrence of a character in a memory block.
* @param s The memory block to search in.
* @param c The character to search for.
* @param n The number of bytes to search in.
* @return A pointer to the first occurrence of the character,
*or NULL if not found.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
			return ((void *) & str[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", (char *)ft_memchr("hello", 'l', 5));
	return (0);
}
*/
