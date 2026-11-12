/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstiter.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tobillet <tobillet@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 14:02:11 by tobillet         #+#    #+#              */
/*   Updated: 2026/10/21 14:03:15 by tobillet        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Iterates through a linked list
* and applies a function to the content of each node.
* @param lst A pointer to the first node of the linked list.
* @param f A function pointer that takes a void pointer
* as an argument and returns nothing.
* The function is applied to the content of each node in the list.
* @return None
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>

static void	show(void *content)
{
	printf("[%s]\n", (char *)content);
}

int	main(void)
{
	t_list	a;
	t_list	b;

	a.content = "a";
	a.next = &b;
	b.content = "b";
	b.next = NULL;
	ft_lstiter(&a, show);
	return (0);
}
*/
