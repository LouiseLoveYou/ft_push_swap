/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strdup.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 11:03:25 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 10:41:31 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Creates a duplicate of a string.
* @param s The string to duplicate.
* @return A pointer to the newly allocated string,
* or NULL if the allocation fails.
*/

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	ptr = (char *) malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*copy;

	copy = ft_strdup("hello");
	printf("%s\n", copy);
	free(copy);
	return (0);
}
*/
