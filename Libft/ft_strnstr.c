/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 10:53:11 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:53:34 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Locates the first occurrence of a substring in a string.
* @param big The string to search in.
* @param little The substring to search for.
* @param len The maximum number of characters to search.
* @return A pointer to the first occurrence of little in big,
* or NULL if not found.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (j < len - i && little[j] != '\0' && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *) big + i);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("hello world", "world", 11));
	return (0);
}
*/
