/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstadd_back.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 13:40:27 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 13:40:47 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Adds a new node at the end of a linked list.
*
* This function takes a pointer to the first node of a linked list and a new
* node to be added. It traverses the list to find the last node and appends
* the new node to it. If the list is empty, the new node becomes the first
* node of the list.
*
* @param lst A pointer to a pointer to the first node of the linked list.
* @param new A pointer to the new node to be added at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
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
	lst = &a;
	ft_lstadd_back(&lst, &b);
	printf("%s\n", (char *)lst->next->content);
	return (0);
}
*/
