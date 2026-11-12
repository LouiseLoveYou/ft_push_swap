/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memset.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 15:52:19 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 13:48:32 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Fills the first n bytes of the memory area pointed to by s
*  with the constant byte c.
*
* @param s Pointer to the memory area to fill.
* @param c The constant byte to fill with.
* @param n The number of bytes to fill.
* @return A pointer to the memory area s.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[4];

	ft_memset(str, 'x', 3);
	str[3] = '\0';
	printf("%s\n", str);
	return (0);
}
*/
