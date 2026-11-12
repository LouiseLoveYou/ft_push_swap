/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcpy.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 09:25:35 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:21:01 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @file ft_strlcpy.c
* @brief Implementation of the strlcpy function.
*
* This function copies up to size - 1 characters from the string src to dst,
* null-terminating the result if size is not 0.
*
* @param dst The destination buffer where the string will be copied.
* @param src The source string to be copied.
* @param size The size of the destination buffer.
* @return The total length of the string it tried to create (length of src).
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>

int	main(void)
{
	char	dst[6];

	ft_strlcpy(dst, "hello", 6);
	printf("%s\n", dst);
	return (0);
}
*/
