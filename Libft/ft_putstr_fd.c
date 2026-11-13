/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putstr_fd.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 09:31:00 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 09:31:11 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Writes a string to a file descriptor.
* @param s The string to write.
* @param fd The file descriptor to write to.
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

/*
int	main(void)
{
	ft_putstr_fd("hello", 1);
	return (0);
}
*/
