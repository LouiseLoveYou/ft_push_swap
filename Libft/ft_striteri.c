/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_striteri.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 14:58:28 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 13:41:23 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Applies a function to each character of a string,
* modifying the string in place.
* @param s The string to modify.
* @param f The function to apply to each character,
* taking the index and character as arguments.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <ctype.h>
#include <stdio.h>

static void	upper(unsigned int i, char *c)
{
	(void)i;
	*c = toupper((unsigned char)*c);
}

int	main(void)
{
	char	str[] = "hello";

	ft_striteri(str, upper);
	printf("%s\n", str);
	return (0);
}
*/
