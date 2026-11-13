/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstadd_front.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 10:07:28 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 10:07:41 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Adds a new node at the beginning of a linked list.
* @param lst A pointer to the pointer of the first node of the list.
* @param new The new node to be added at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	*lst;

	a.content = "a";
	a.next = NULL;
	b.content = "b";
	b.next = NULL;
	lst = &b;
	ft_lstadd_front(&lst, &a);
	printf("%s %s\n", (char *)lst->content, (char *)lst->next->content);
	return (0);
}
*/
