/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcmp.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 10:50:32 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:52:14 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Compares two memory areas.
* @param s1 The first memory area.
* @param s2 The second memory area.
* @param n The number of bytes to compare.
* @return An integer less than, equal to,
* or greater than zero if the first n bytes of s1 is found,
* respectively, to be less than, to match,
* or be greater than the first n bytes of s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_memcmp("abc", "abd", 3));
	return (0);
}
*/
