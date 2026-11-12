/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strtrim.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 11:36:17 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 11:37:46 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Trims characters from the beginning and end of a string.
* @param s1 The string to be trimmed.
* @param set The set of characters to trim
*  @return A pointer to the newly allocated trimmed string,
* or NULL if the allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = (char *) malloc((end - start + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + start, end - start + 1);
	return (trimmed_str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_strtrim("  hello  ", " ");
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
