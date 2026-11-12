/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 11:22:34 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 13:48:41 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*** @brief Concatenates two strings into a new string.
* @param s1 The first string to concatenate.
* @param s2 The second string to concatenate.
* @return A pointer to the newly allocated string containing the concatenation
* of s1 and s2, or NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	ft_memcpy(joined_str, s1, len1);
	ft_memcpy(joined_str + len1, s2, len2);
	joined_str[len1 + len2] = '\0';
	return (joined_str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_strjoin("hello ", "world");
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
