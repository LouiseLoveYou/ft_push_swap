/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_toupper.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 09:45:54 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 10:20:51 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Converts a character to uppercase.
* @param c The character to convert.
* @return The uppercase version of the character,
or the original character if it is not a lowercase letter.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_toupper('a'));
	return (0);
}
*/
