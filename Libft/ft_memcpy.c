/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcpy.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 09:04:55 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:32:18 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Copies n bytes from memory area src to memory area dest.
*
* @param dest Pointer to the destination memory area.
* @param src Pointer to the source memory area.
* @param n The number of bytes to copy.
* @return A pointer to the destination memory area dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	dst[6];

	ft_memcpy(dst, "hello", 6);
	printf("%s\n", dst);
	return (0);
}
*/
