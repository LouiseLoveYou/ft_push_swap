/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_tolower.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 09:51:01 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:20:48 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Converts a character to lowercase.
* @param c The character to convert.
* @return The lowercase version of the character, or the original character
* if it is not an uppercase letter.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_tolower('A'));
	return (0);
}
*/
