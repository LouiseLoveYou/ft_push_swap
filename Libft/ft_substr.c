/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_substr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 11:10:33 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 11:13:40 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
* @brief Allocates and returns a substring from the string 's'.
*
* This function allocates memory for a new string that is a substring of 's',
* starting at index 'start' and with a maximum length of 'len'. The resulting
* string is null-terminated.
*
* @param s The string from which to create the substring.
* @param start The index of the first character to include in the substring.
* @param len The maximum number of characters to include in the substring.
* @return A pointer to the newly allocated substring,
* or NULL if allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *) malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_substr("hello", 1, 3);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
