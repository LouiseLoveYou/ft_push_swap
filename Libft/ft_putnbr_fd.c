/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbr_fd.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 09:34:05 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 09:34:43 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Writes an integer to a file descriptor.
* @param n The integer to write.
* @param fd The file descriptor to write to.
*  */

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}
*/
