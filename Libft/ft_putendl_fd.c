/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putendl_fd.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 09:32:14 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 09:32:35 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Writes a string followed by a newline to a file descriptor.
* @param s The string to write.
* @param fd The file descriptor to write to.
* */

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

/*
int	main(void)
{
	ft_putendl_fd("hello", 1);
	return (0);
}
*/
