/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strmapi.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 14:15:37 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 14:48:35 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Applies a function to each character of a string, creating a new string.
* @param s The input string.
* @param f The function to apply to each character,
* taking the index and character as arguments.
* @return A pointer to the newly allocated string
* resulting from the application of f,
* or NULL if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
#include <ctype.h>
#include <stdio.h>

static char	upper(unsigned int i, char c)
{
	(void)i;
	return (toupper((unsigned char)c));
}

int	main(void)
{
	char	*str;

	str = ft_strmapi("hello", upper);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
