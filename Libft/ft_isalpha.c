/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_isalpha.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 14:22:50 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/20 09:02:26 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
int	main(void)
{
	if (!ft_isalpha('z') || ft_isalpha('4'))
		return (1);
	return (0);
}
*/
