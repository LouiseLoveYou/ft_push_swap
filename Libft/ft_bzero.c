/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_bzero.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 15:53:12 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 15:02:13 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/**
* @brief Sets the first n bytes of the memory area pointed to by s to zero.
*
* This function sets the first n bytes of the memory area pointed to by s
* to zero. It is equivalent to calling memset(s, 0, n).
*
* @param s A pointer to the memory area to be set to zero.
* @param n The number of bytes to set to zero.
*/
// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*str;
// 	size_t			i;

// 	str = (unsigned char *) s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		str[i] = 0;
// 		i++;
// 	}
// }

/*
#include <stdio.h>

int	main(void)
{
	char	str[5] = "test";

	ft_bzero(str, 4);
	printf("%d\n", str[0]);
	return (0);
}
*/
