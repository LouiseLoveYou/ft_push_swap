/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 11:02:31 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/27 15:09:06 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Allocates memory for an array of elements and initializes it to zero.
*
* This function allocates memory for an array of `nmemb` elements, each of
* size `size`, and initializes the allocated memory to zero. It returns a
* pointer to the allocated memory, or NULL if the allocation fails.
*
* @param nmemb The number of elements to allocate.
* @param size The size of each element in bytes.
* @return A pointer to the allocated memory, or NULL if the allocation fails.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;

// 	str = ft_calloc(2, 1);
// 	if (!str)
// 	{
// 		printf("allocation failed: NULL\n");
// 		return (1);
// 	}
// 	printf("%d\n", str[0]);
// 	printf("%d\n", str[1]);
// 	free(str);
// 	return (0);
// }
