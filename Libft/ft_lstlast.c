/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstlast.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 13:32:34 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 13:33:04 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Returns the last node of a linked list.
*
* This function traverses the linked list starting from the given node
* and returns a pointer to the last node in the list. If the list is empty,
* it returns NULL.
*
* @param lst A pointer to the first node of the linked list.
* @return A pointer to the last node of the linked list,
* or NULL if the list is empty.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	printf("%s\n", (char *)ft_lstlast(&a)->content);
	return (0);
}
*/
