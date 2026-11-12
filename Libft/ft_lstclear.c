/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstclear.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 14:00:41 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 14:01:15 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Deletes all nodes in a linked list and frees their memory.
*
* @param lst A pointer to the first node in the list.
* @param del A function pointer to a function that takes a void pointer
* and frees the memory associated with the content of each node.
* @return None
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	a->content = malloc(1);
	b->content = malloc(1);
	a->next = b;
	b->next = NULL;
	ft_lstclear(&a, free);
	printf("%d\n", a == NULL);
	return (0);
}
*/
