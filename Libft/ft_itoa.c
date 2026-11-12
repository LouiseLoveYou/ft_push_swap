/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 13:48:19 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 13:51:53 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Calculates the length of the string needed to represent the number.
* @param n The number to calculate the length for.
* @return The length of the string needed to represent the number.
*/

static size_t	ft_num_len(int n)
{
	long	num;
	size_t	len;

	num = n;
	len = (n <= 0);
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/**
* @brief Fills the string with the digits of the number.
* @param str The string to fill.
* @param num The number to convert.
* @param len The length of the string.
*/

static void	ft_fill_num(char *str, long num, size_t len)
{
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
}

/**
* @brief Converts an integer to a string.
* @param n The integer to convert.
* @return A pointer to the resulting string, or NULL if allocation fails.
*
*/

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;

	len = ft_num_len(n);
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		num = n;
		if (n < 0)
		{
			str[0] = '-';
			num = -num;
		}
		ft_fill_num(str, num, len);
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_itoa(-42);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
