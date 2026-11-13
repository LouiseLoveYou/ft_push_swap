/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putchar_fd.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 09:29:11 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 09:30:01 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Writes a character to a file descriptor.
* @param c The character to write.
* @param fd The file descriptor to write to.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{
	ft_putchar_fd('a', 1);
	return (0);
}
*/
