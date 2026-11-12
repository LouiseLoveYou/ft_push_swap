/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstsize.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 10:20:31 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 10:24:00 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
* @brief Counts the number of nodes in a linked list.
* @param lst A pointer to the first node of the list.
* @return The number of nodes in the list.
*
*/

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	a;
	t_list	b;

	a.content = "a";
	a.next = &b;
	b.content = "b";
	b.next = NULL;
	printf("%d\n", ft_lstsize(&a));
	return (0);
}
*/
