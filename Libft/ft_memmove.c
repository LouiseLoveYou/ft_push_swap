/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 09:06:34 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 09:29:23 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Copies n bytes from memory area src to memory area dest.
* The memory areas may overlap.
*
* @param dest Pointer to the destination memory area.
* @param src Pointer to the source memory area.
* @param n The number of bytes to copy.
* @return A pointer to the destination memory area dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[8] = "abcdef";

	ft_memmove(str + 2, str, 3);
	printf("%s\n", str);
	return (0);
}
*/
